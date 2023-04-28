#include "shell.h"

/**
 * _strncpy - copies string
 *
 * @dest: destination string to be copied to
 * @src: source string
 * @n: amount of characters to be copied
 *
 * Return: the copied string
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
size_t i;
char *s = dest;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];
for ( ; i < n; i++)
dest[i] = '\0';
return (s);
}


/**
 * _strncat - concatenates strings
 *
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 *
 * Return: concatenated string
 */

char *_strncat(char *dest, const char *src, size_t n)
{
size_t dest_len = strlen(dest);
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';
return (dest);
}

/**
 * _strchr - locates a character in a string
 *
 * @s: string to be parsed
 * @c: character to look for
 *
 * Return: a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}
if (*s == c)
return (s);
return (NULL);
}
