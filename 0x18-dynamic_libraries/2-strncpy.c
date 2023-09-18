#include "main.h"

/**
* _strncpy - Copies a string.
* @dest: The destination buffer.
* @src: The source string.
* @n: The maximum number of characters to copy.
*
* Return: A pointer to the destination buffer.
*/
char *_strncpy(char *dest, char *src, int n)
{
int x;

for (x = 0; x < n && src[x]; x++)
{
dest[x] = src[x];
}
for (; x < n; x++)
{
dest[x] = '\0';
}

return (dest);
}

