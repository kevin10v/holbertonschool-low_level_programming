#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - Prints an error message to stderr and exits.
 * @code: exit code.
 * @message: error message.
 * @arg: argument to include in the message.
 */
void print_error_and_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
		print_error_and_exit(97, "Usage: %s file_from file_to\n", av[0]);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	do {
		r = read(fd_from, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit(98, "Error: Can't read from file %s\n", av[1]);
		}
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit(99, "Error: Can't write to %s\n", av[2]);
		}
	} while (r > 0);

	if (close(fd_from) == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", av[1]);
	if (close(fd_to) == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", av[2]);

	return (0);
}
