#include "main.h"
#include <stdio.h>

/**
 * _strncat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to use from src.
 *
 * Return: A pointer to the resulting string dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0, i = 0;

	/* Get the length of the destination string */
	while (dest[dest_len] != '\0')
		dest_len++;

	/* Append the source string up to n bytes */
	while (src[i] != '\0' && i < n)
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	/* Add the null terminator */
	dest[dest_len + i] = '\0';

	return (dest);
}
