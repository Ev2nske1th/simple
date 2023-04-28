#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 *
 * @s: The string whose length to check.
 * Return: The integer length of string.
 */

int _strlen(char *s)
{
    int len = 0;

    if (s == NULL)
        return (0);

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return (len);
}

/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */

int _strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return (*s1 - *s2);

        s1++;
        s2++;
    }

    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if a string starts with another string.
 * @haystack: The string to search.
 * @needle: The substring to find.
 * Return: A pointer to the next character of haystack if needle is found,
 *         otherwise NULL.
 */

char *starts_with(const char *haystack, const char *needle)
{
    while (*needle != '\0')
    {
        if (*needle++ != *haystack++)
            return (NULL);
    }

    return ((char *) haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 * Return: A pointer to the destination buffer.
 */

char *_strcat(char *dest, char *src)
{
    char *ret = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0')
        *dest++ = *src++;

    *dest = '\0';

    return (ret);
}
