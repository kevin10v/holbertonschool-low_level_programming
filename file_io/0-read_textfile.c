#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: The name of the file to read
 * @letters: The number of letters it should read and print
 *
 * Return: Actual number of letters it could read and print,
 *         or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t rcount, wcount;
char *buffer;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(fd);
return (0);
}

rcount = read(fd, buffer, letters);
if (rcount == -1)
{
free(buffer);
close(fd);
return (0);
}

wcount = write(STDOUT_FILENO, buffer, rcount);
if (wcount == -1 || wcount != rcount)
{
free(buffer);
close(fd);
return (0);
}

free(buffer);
close(fd);
return (wcount);
}
