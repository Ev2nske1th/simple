#include "shell.h"
/**
 * is_cmd - determines if file is an executable command
 *
 * @info: info struct
 * @path: path to file
 *
 * Return: 1 if true, 0 otherwise
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	if (!path || stat(path, &st) != 0)
		return (0);

	return (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR));
}


/**
 * dup_chars - duplicates character
 *
 * @pathstr: PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	char *buf;
	int i, k;

	buf = malloc((stop - start + 1) * sizeof(char));
	if (!buf)
		return (NULL);

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = '\0';
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 *
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i, curr_pos;
	char *path;

	if (!pathstr)
		return (NULL);

	if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	curr_pos = 0;
	for (i = 0; pathstr[i] != '\0'; i++)
	{
		if (pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!path)
				return (NULL);
			_strcat(path, "/");
			_strcat(path, cmd);
			if (is_cmd(info, path))
				return (path);
			curr_pos = i + 1;
			free(path);
		}
	}
	path = dup_chars(pathstr, curr_pos, i);
	if (!path)
		return (NULL);

	_strcat(path, "/");
	_strcat(path, cmd);
	if (is_cmd(info, path))
		return (path);
	free(path);

	return (NULL);
}
