#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_data_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */


char *create_data_buffer(char *file);
void close_file(int fd);

char *create_data_buffer(char *file) {
char *buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL) {
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

void close_file(int fd) {
if (close(fd) == -1) {
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

int main(int argc, char *argv[]) {
if (argc != 3) {
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

char *buffer = create_data_buffer(argv[2]);
int from = open(argv[1], O_RDONLY), to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
ssize_t r, w;

do {
if ((r = read(from, buffer, 1024)) == -1) {
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

if ((w = write(to, buffer, r)) == -1) {
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
} while (r > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}
