#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void closefd(int fd1, int fd2);
void print_error(char *msg, char *file, int code);
int open_file_read(const char *filename);
int open_file_write(const char *filename);
void copy_file(int fdr, int fdw, const char *src, const char *dest);

/**
 * main - Entry point, copies contents from file_from to file_to.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, exits with codes on failure.
 */
int main(int argc, char *argv[])
{
	int fdr, fdw;
	char *file_from, *file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	fdr = open_file_read(file_from);
	fdw = open_file_write(file_to);
	copy_file(fdr, fdw, file_from, file_to);
	closefd(fdr, fdw);

	return (0);
}

/**
 * open_file_read - Opens a file for reading.
 * @filename: Name of the file.
 * Return: File descriptor, exits if it fails.
 */
int open_file_read(const char *filename)
{
	int fdr = open(filename, O_RDONLY);
	char buffer[BUFFER_SIZE];
	ssize_t n;

	if (fdr == -1)
		print_error("Error: Can't read from file", (char *)filename, 98);

	n = read(fdr, buffer, BUFFER_SIZE);
	if (n == -1)
	{
		close(fdr);
		print_error("Error: Can't read from file", (char *)filename, 98);
	}
	lseek(fdr, 0, SEEK_SET);
	return (fdr);
}

/**
 * open_file_write - Opens a file for writing.
 * @filename: Name of the file.
 * Return: File descriptor, exits if it fails.
 */
int open_file_write(const char *filename)
{
	int fdw = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fdw == -1)
		print_error("Error: Can't write to", (char *)filename, 99);
	return (fdw);
}

/**
 * copy_file - Copies data from one file to another.
 * @fdr: Source file descriptor.
 * @fdw: Destination file descriptor.
 * @src: Source filename.
 * @dest: Destination filename.
 */
void copy_file(int fdr, int fdw, const char *src, const char *dest)
{
	char buffer[BUFFER_SIZE];
	ssize_t n_read, n_written;

	while ((n_read = read(fdr, buffer, BUFFER_SIZE)) > 0)
	{
		n_written = write(fdw, buffer, n_read);
		if (n_written == -1)
		{
			closefd(fdr, fdw);
			print_error("Error: Can't write to", (char *)dest, 99);
		}
	}
	if (n_read == -1)
	{
		closefd(fdr, fdw);
		print_error("Error: Can't read from file", (char *)src, 98);
	}
}

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
 * print_error - Prints an error message and exits.
 * @msg: Error message.
 * @file: Filename causing the error.
 * @code: Exit code.
 */
void print_error(char *msg, char *file, int code)
{
	dprintf(STDERR_FILENO, "%s %s\n", msg, file);
	exit(code);
}
