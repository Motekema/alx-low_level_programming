#include "main.h"

/**
 * _puts - Prints a string.
 * @str: The string to be printed.
 */
void _puts(char *str)
{
    int a = 0;

    while (str[a] != '\0')
    {
        _putchar(str[a]);
        a++;
    }
    _putchar('\n');
}
