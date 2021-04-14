#include "holberton.h"

/**
 *no_file_er - write an error message if file is not found
 *@argv: the array of passed in function argument strings
 *@ar: the array of tokens entered by the user
 *@cmdnum: the number of commands entered
 *@line: the command line entered by the user
 *@nline: the command line without the newline character
 *
 *Return: void
 */
void no_file_er(char **argv, char **ar, int cmdnum, char *line, char *nline)
{
	char *num;

	num = printint(cmdnum);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar[0], _strlen(ar[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(num);
	free_all(line, nline, ar);
	exit(0);
}
