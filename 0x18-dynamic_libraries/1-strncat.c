#include "main.h"

/**
* _strncat - Concatenates two strings.
* @dest: The destination string.
* @src: The source string.
* @n: The maximum number of characters to append.
*
* Return: A pointer to the resulting string @dest.
*/
char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0;
int src_len = 0;

while (dest[dest_len] != '\0')
dest_len++;

while (src[src_len] != '\0' && src_len < n)
{
dest[dest_len] = src[src_len];
dest_len++;
src_len++;
}

dest[dest_len] = '\0';

return (dest);
}
