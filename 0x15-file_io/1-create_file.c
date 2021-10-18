#include "main.h"

/**
 * _strlen - claculates the length of a string
 * @str: string
 * Return: length of string
 */

int _strlen(char *str)
{
int len;

for (len = 0; str[len] != '\0'; len++)
;

return (len);
}

/**
 * create_file - creates a file with rw permissions and writes
 * content in the file if it already exists
 * @filename: name of new file
 * @text_content: content to write in new file
 * Return: 1 on success, -1 on error
 */

int create_file(const char *filename, char *text_content)
{
int fd;
int n_write;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);
if (!text_content)
{
close(fd);
return (1);
}

n_write = write(fd, text_content, _strlen(text_content));
if (n_write == -1 || n_write != _strlen(text_content))
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
