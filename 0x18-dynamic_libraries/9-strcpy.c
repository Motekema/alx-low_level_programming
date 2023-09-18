#include "main.h"

/**
* _strcpy - copy the string pointed to by src to dest
* @dest: the destination buffer
* @src: the source string
* Return: returns the pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
	int h;

	for (h = 0; src[h] != '\0'; h++)
		dest[h] = src[h];
	dest[h] = '\0';
	return (dest);
}
