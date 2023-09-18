#include "main.h"

/**
* _memset - Fills the first @n bytes of the memory area pointed to by @s
*           with the constant byte @b
*
* @s: Pointer to the memory area
* @b: The constant byte to fill
* @n: Number of bytes to fill
*
* Return: A pointer to the memory area @s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int x = 0;

while (x < n)
{
s[x] = b;
x++;
}

return (s);
}
