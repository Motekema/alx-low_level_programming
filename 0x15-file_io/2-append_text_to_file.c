#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: The string to add to the end of the file.
* Return: 1 on success and -1 on failure or filename is NULL - -1.
*/

int append_text_to_file(const char *filename, char *text_content)
{
int z, y, gen = 0;

if (text_content != NULL)
{
for (gen = 0; text_content[gen];)
gen++;
}

if (filename == NULL)
return (-1);

z = open(filename, O_WRONLY | O_APPEND);
y = write(z, text_content, gen);

if (z == -1 || y == -1)
return (-1);

close(z);

return (1);
}

