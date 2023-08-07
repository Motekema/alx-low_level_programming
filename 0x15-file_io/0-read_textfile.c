#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read and print the contents of a text file.
 * @filename: The name of the text file to read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t cd;
ssize_t s;
ssize_t a;

cd = open(filename, O_RDONLY);
if (cd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
s = read(cd, buf, letters);
a = write(STDOUT_FILENO, buf, s);

free(buf);
close(cd);
return (a);
}
