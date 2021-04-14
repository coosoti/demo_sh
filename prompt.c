#include "holberton.h"

/**
 *printprompt - prints the shell prompt
 *
 *Return: void
 */
void printprompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
