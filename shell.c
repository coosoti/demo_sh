#include "holberton.h"

/**
 *main - entry point for shell program
 *@ac: the number of arguments passed
 *@av: an array of strings of the arguments passed
 *@env: the current environment
 *
 *Description: function will read a line, break it into tokens, and execute
 *the call, then return to main when end of file is reached
 *Return: 0 when EOF is reached (ie user presses Ctrl + D)
 */
int main(int ac, char **av, char **env)
{
	char *line, *newline;
	size_t len = 0;
	ssize_t characters;
	char **tokenarray;
	int cmdnum = 0;

	(void)ac, (void)av;
	while (1)
	{
		line = NULL;
		len = 0;
		cmdnum++;
		if (isatty(STDIN_FILENO) == 1)
			printprompt();
		signal(SIGINT, ctrlc);
		characters = getline(&line, &len, stdin);
		if (characters == EOF || characters == -1)
			return (ctrld(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		newline = _reallocchar(line);
		if (newline == NULL)
		{
			free(line);
			return (0);
		}
		tokenarray = tokensplit(newline);
		if (tokenarray == NULL)
		{
			free(line);
			free(newline);
			return (0);
		}
		exec(tokenarray, env, av, line, newline, cmdnum);
		free_all(line, newline, tokenarray);
	}
}

/**
 *tokensplit - splits a line into tokens and stores into a char array
 *@line: the line string to split
 *
 *Return: the array of strings
 */
char **tokensplit(char *line)
{
	int i = 0;
	int tokencount = 0;
	char **tokenarray;
	char *token, *tokencopy;

	if (line == NULL)
		return (NULL);
	while (*(line + i) != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'
				       || line[i + 1] == '\t'))
			tokencount++;
		i++;
	}

	i = 0;
	tokenarray = malloc(sizeof(char *) * (tokencount + 1));
	if (tokenarray == NULL)
		return (NULL);
	token = strtok(line, DELIMS);
	while (token != NULL)
	{
		tokencopy = _strdup(token);
		if (tokencopy == NULL)
		{
			free(tokenarray);
			return (NULL);
		}
		*(tokenarray + i) = tokencopy;
		token = strtok(NULL, DELIMS);
		i++;
	}
	*(tokenarray + i) = NULL;
	return (tokenarray);
}
