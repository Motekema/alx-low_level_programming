#include "main.h"

/**
* _strstr - Locates a substring in a string.
* @haystack: The string to search within.
* @needle: The substring to find.
*
* Return: A pointer to the beginning of the substring if found, or NULL if
*         the substring is not found.
*/
char *_strstr(char *haystack, char *needle)
{
unsigned int z = 0, b = 0;

while (haystack[z])
{
while (needle[b] && (haystack[z] == needle[0]))
{
if (haystack[z + b] == needle[b])
b++;
else
break;
}
if (needle[b])
{
z++;
b = 0;
}
else
return (haystack + z);
}
return (NULL);
}
