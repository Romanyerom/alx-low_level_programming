#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i;

	/* find the length of the destination string */
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* concatenate the source string to the destination string */
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	/* add a null terminator to the end of the destination string */
	dest[dest_len + i] = '\0';

	/* return a pointer to the destination string */
	return (dest);
}
