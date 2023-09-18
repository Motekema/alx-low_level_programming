#include "main.h"

/**
 * _strlen - Return the length of the string.
 * @s: The string to be measured.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return (len);
}
