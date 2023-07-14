#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_and_exit - Prints an error message and exits with the given code.
 * @code: The exit code.
 * @message: The error message to print.
 */

void error_and_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to, read_status, write_status;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_and_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_and_exit(98, "Error: Can't read from file");

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_and_exit(99, "Error: Can't write to file");

	while ((read_status = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_status = write(fd_to, buffer, read_status);
		if (write_status == -1)
			error_and_exit(99, "Error: Can't write to file");
	}

	if (read_status == -1)
		error_and_exit(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		error_and_exit(100, "Error: Can't close file descriptor");

	if (close(fd_to) == -1)
		error_and_exit(100, "Error: Can't close file descriptor");

	return (0);
}
