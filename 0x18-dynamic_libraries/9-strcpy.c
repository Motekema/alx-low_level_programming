#include "main.h"

/**
* _strcpy - copy the string pointed to by src to dest
* @dest: the destination buffer
* @src: the source string
* Return: returns the pointer to dest
*/

char *_strcpy(char *dest, const char *src)
{
char *start = dest;

while ((*dest++ = *src++))
;

return (start);
}
