#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * closefd - Closes two file descriptors and handles errors.
 * @fd1: First file descriptor.
 * @fd2: Second file descriptor.
 */
void closefd(int fd1, int fd2)
{
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}
}

/**
 * handle_error - Handles common error messages and exits.
 * @code: Exit code.
 * @message: Error message.
 * @filename: File name to print in error.
 */
void handle_error(int code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, message, filename);
	exit(code);
}

/**
 * copy_file - Copies contents of one file to another.
 * @file_from: Source file.
 * @file_to: Destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fdr, fdw, n_read, n_written;
	char buffer[BUFFER_SIZE];

	fdr = open(file_from, O_RDONLY);
	if (fdr == -1)
		handle_error(98, "Error: Can't read from file %s\n", file_from);

	n_read = read(fdr, buffer, BUFFER_SIZE);
	if (n_read == -1)
	{
		close(fdr);
		handle_error(98, "Error: Can't read from file %s\n", file_from);
	}

	fdw = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdw == -1)
	{
		close(fdr);
		handle_error(99, "Error: Can't write to %s\n", file_to);
	}

	while (n_read > 0)
	{
		n_written = write(fdw, buffer, n_read);
		if (n_written == -1)
		{
			closefd(fdr, fdw);
			handle_error(99, "Error: Can't write to %s\n", file_to);
		}
		n_read = read(fdr, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			closefd(fdr, fdw);
			handle_error(98, "Error: Can't read from file %s\n", file_from);
		}
	}

	closefd(fdr, fdw);
}

/**
 * main - Entry point. Validates arguments and calls file copy.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
