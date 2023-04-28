#include "shell.h"


/**
 * interactive - checks if the shell is in interactive mode
 *
 * @info: struct containing shell info
 *
 * Return: 1 if shell is in interactive mode, otherwise 0
 */

int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 *
 * @c: character to check
 * @delim: string of delimiters
 *
 * Return: 1 if character is a delimiter, 0 otherwise
 */

int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim == c)
return (1);
delim++;
}
return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 *
 * @c: character to check
 *
 * Return: 1 if character is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 *
 * @s: string to convert
 *
 * Return: integer representation of string, or 0 if no numbers found
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0;
unsigned int result = 0;

for (i = 0; s[i]; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result = (result * 10) + (s[i] - '0');
}
else if (flag == 1)
{
break;
}
}
return (sign *result);
}
