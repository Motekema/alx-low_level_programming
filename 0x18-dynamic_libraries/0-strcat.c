#include "main.h"

/**
* _strcat - Concatenates two strings.
* @dest: Destination string
* @src: Source string
*
* Return: Pointer to the resulting string @dest
*/
char *_strcat(char *dest, char *src)
{
int a = 0;
int o = 0;

while (dest[a] != '\0')
a++;

while (src[o] != '\0')
{
dest[a] = src[o];
o++;
a++;
}

return (dest);
}
