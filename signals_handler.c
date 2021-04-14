#include "holberton.h"

/**
 *ctrld_handler - actions for when Ctrl+D is entered into the shell
 *@line: the main line buffer to free
 *
 *Return: 0 on success
 */
int ctrld_handler(char *line)
{
	free(line);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
/**
 *ctrlc_handler - control C handler
 *@signum: the signal number received
 *
 *Return: void
 */
void ctrlc_handler(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n$ ", 3);
}
