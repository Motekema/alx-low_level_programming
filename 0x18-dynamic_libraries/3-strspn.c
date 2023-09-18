#include "main.h"

/**
* _strspn - Gets the length of a prefix substring.
* @s: The initial segment.
* @accept: A string consisting only of bytes.
*
* Return: The number of bytes in the initial segment of s that consist
* only of bytes from accept.
*/
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int i, j;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == ' ')
{
return (count);
}

for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
{
count++;
break;
}
}
}

return (count);
}
