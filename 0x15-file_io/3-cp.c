#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *creat_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates bytes for buffer
 * @fine: name of file buffer is storing chars.
 * Return: pointer to newly allocated buffer
 */

char *create_buffer(char *file)
{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

/**
 * close_file - close file descriptors
 * @fd: file descriptor for closure
 */

void close_file(int fd)
{
int i;
i = close(fd);
if (i == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - copy file contents to another
 * @argc: arguments supplied to e program
 * @argv: pointer arrays to arguments
 * Return: 1 is success
 */

int main(int argc, char *argv[])
{
int from, to, s, d;
char *buffer;
if (argc != 3)
{

dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
s = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || s == -1)
{

dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
d = write(to, buffer, s);
if (to == -1 || d == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
s = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (s > 0);
free(buffer);
close_file(from);
close_file(to);
return (0);
}
