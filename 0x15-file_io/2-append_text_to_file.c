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
 * append_text_to_file - append text content to a file
 * @filename: name of file
 * @text_content: content to append to file
 * Return: 1 on success, -1 on error
 */

int append_text_to_file(const char *filename, char *text_content)
{
int fd;
int n_write;

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
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
