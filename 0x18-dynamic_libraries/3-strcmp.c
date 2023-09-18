#include "main.h"

/**
* _strcmp - Compares two strings.
* @s1: The first string to compare.
* @s2: The second string to compare.
*
* Return: An integer less than, equal to, or greater than zero if s1 is
* found, respectively, to be less than, to match, or be greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}

if (*s1 == *s2)
return (0);

return (*s1 - *s2);
}

