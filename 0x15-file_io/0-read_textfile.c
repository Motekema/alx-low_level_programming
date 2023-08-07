#include "main.h"
#include <stdlib.h>

/**
* function that reads a text file and prints it to the POSIX standard output
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed
* when 0 function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t cd;
ssize_t t;
ssize_t w;

cd = open(filename, O_RDONLY);
if (cd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(cd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(cd);
return (w);
}
