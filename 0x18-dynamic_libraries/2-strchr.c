#include "main.h"
#include <stddef.h>

/**
* _strchr - Locates a character in a string.
* @s: The string to be checked.
* @c: The character to find.
*
* Return: A pointer to the first occurrence of the character in the string @s.
*         If the character is not found, returns NULL.
*/
char *_strchr(char *s, char c)
{
while (*s)
{
if (*s != c)
s++;
else
return (s);
}

if (c == '\0')
return (s);

return (NULL);
}
