#include "holberton.h"

/**
 *execute_cmd - executes a line of code in the shell
 *@ar: the array of strings to execute
 *@env: the environment variable
 *@av: the array of command line argument strings
 *@line: user-entered input
 *@nline: user-entered input with newline truncated
 *@cdnum: the number of commands entered by the user - for error handling
 *
 *Return: 0 on success, -1 on failure
 */
int execute_cmd(char **ar, char **env, char **av, char *line, char *nline, int cdnum)
{
	pid_t my_pid;
	char *concat;
	int signal;
	struct stat status;

	if (ar == NULL || *ar == NULL || av == NULL || *av == NULL)
		return (-1);
	if (env == NULL || *env == NULL)
		return (-1);
	if (checkBuiltins(ar, env, line, nline, cdnum) == 0)
		return (0);
	my_pid = fork();
	if (my_pid == -1)
	{
		write(STDOUT_FILENO, "Error forking", 13);
		return (-1);
	}
	if (my_pid == 0)
	{
		if (ar[0][0] == '/')
		{
			if (stat(ar[0], &status) == -1)
				error_handler(av, ar, cdnum, line, nline);
			if (access(ar[0], X_OK) == -1)
				error_handler(av, ar, cdnum, line, nline);
			execve(ar[0], ar, NULL);
		}
		else
		{
			concat = path_handler(ar[0], env);
			if (concat == NULL)
				error_handler(av, ar, cdnum, line, nline);
			else
				execve(concat, ar, NULL);
		}
	}
	else
		wait(&signal);
	return (0);
}
