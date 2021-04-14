#include "holberton.h"

/**
 *shellPrompt - prints the shell prompt
 *
 *Return: void
 */
void shellPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
