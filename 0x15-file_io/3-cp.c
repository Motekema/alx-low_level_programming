#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_exit(const char *message) {
dprintf(STDERR_FILENO, "%s\n", message);
exit(1);
}

char *create_buffer(char *file) {
char *buffer = malloc(1024);
if (buffer == NULL) {
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return buffer;
}

void close_file(int fd) {
if (close(fd) == -1) {
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

int main(int argc, char *argv[]) {
int from, to;
ssize_t r, w;
char *buffer;

if (argc != 3) error_exit("Usage: cp file_from file_to");

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || r == -1) {
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

w = write(to, buffer, r);
if (to == -1 || w == -1) {
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}
