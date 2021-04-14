#include "holberton.h"

/**
 *exit_handler - handles exit builtin
 *@array: the array of strings to execute
 *@line: line of user-entered input
 *@newline: user-entered lined with newline truncated
 *@cdnum: the number of commands entered by the user
 *
 *Return: 0 upon success, or some specific exit code specified by user
 */
int exit_handler(char **array, char *line, char *newline, int cdnum)
{
	int num, j = 0;
	char *cmdnum;

	if (array[1] == NULL)
	{
		free_all(line, newline, array);
		_exit(0);
	}

	else
	{
		num = _atoi(array[1]);
		if (num == -1)
		{
			cmdnum = print_int(cdnum);
			write(STDERR_FILENO, "./hsh: ", 7);
			write(STDERR_FILENO, cmdnum, _strlen(cmdnum));
			write(STDERR_FILENO, ": exit: Illegal number: ", 24);
			while (array[1][j] != '\0')
				j++;
			write(STDOUT_FILENO, array[1], j);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		free_all(line, newline, array);
		exit(num);
	}
}
/**
 *cd_handler - hands the cd builtin
 *@array: the array of command line strings
 *@env: the environment variable
 *
 *Return: 0 upon success
 */
int cd_handler(char **array, char **env)
{
	int i = 0;
	char cwd[1024];
	char *newdir;

	if (array[1] == NULL)
	{
		if (chdir(_getenv("HOME", env)) == -1)
		{
			perror("./hsh");
			write(STDERR_FILENO, "cd: can't cd to home\n", 21);
		}
	}
	else
	{
		getcwd(cwd, 1024);
		while (cwd[i] != '\0')
			i++;
		cwd[i++] = '/';
		cwd[i] = '\0';
		newdir = _strconcat(cwd, array[1]);
		if (newdir == NULL)
			return (0);
		if (chdir(newdir) == -1)
		{
			perror("./hsh");
			write(STDERR_FILENO, "can't cd into directory\n", 24);
		}
		free(newdir);
	}
	return (0);
}
/**
 *env_handler - handles env builtin
 *@env: environment variable
 *
 *Return: 0 on success
 */
int env_handler(char **env)
{
	int i = 0, length = 0;

	while (env[i] != NULL)
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 *checkBuiltins - implement exit, buit-in, that exits the shell
 *@ar: the array of strings to execute
 *@env: the environment variable
 *@line: user-entered input
 *@newline: user-entered input without newline character
 *@cdnum: the number of commands entered by the user
 *
 *Return: 0 when successfully running a builtin, 1 when builtin not found
 */
int checkBuiltins(char **ar, char **env, char *line, char *newline, int cdnum)
{
	if (ar == NULL || *ar == NULL)
		return (1);
	if (env == NULL || *env == NULL)
		return (1);
	if (_strcmp((ar[0]), "exit") == 0)
		return (exit_handler(ar, line, newline, cdnum));
	else if (_strcmp((ar[0]), "cd") == 0)
		return (cd_handler(ar, env));
	else if (_strcmp((ar[0]), "env") == 0)
		return (env_handler(env));
	else
		return (1);
}
