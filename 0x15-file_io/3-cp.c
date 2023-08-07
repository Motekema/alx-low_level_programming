#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
*
* Return: A pointer to the newly-allocated buffer.
*/

char *create_buffer(char *file);
void close_file(int fd);

void error_exit(const char *message) {
dprintf(STDERR_FILENO, "%s\n", message);
exit(1);
}

int main(int argc, char *argv[]) {
char *buffer;
int from, to;
ssize_t bytes_read, bytes_written;

if (argc != 3) {
error_exit("Usage: cp file_from file_to");
}

buffer = create_buffer(argv[2]);

from = open(argv[1], O_RDONLY);
if (from == -1) {
error_exit("Error: Can't read from file");
}

to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (to == -1) {
error_exit("Error: Can't write to file");
}

while ((bytes_read = read(from, buffer, sizeof(buffer))) > 0) {
bytes_written = write(to, buffer, bytes_read);
if (bytes_written == -1) {
error_exit("Error: Can't write to file");
}
}

if (bytes_read == -1) {
error_exit("Error: Can't read from file");
}

if (close(from) == -1 || close(to) == -1) {
error_exit("Error: Can't close file descriptor");
}

return (0);
}
