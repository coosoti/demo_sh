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
	ssize_t lineSize;
	char **t_array;
	int cmdnum = 0;

	(void)ac, (void)av;
	while (1)
	{
		line = NULL;
		len = 0;
		cmdnum++;
		if (isatty(STDIN_FILENO) == 1)
			shellPrompt();
		signal(SIGINT, ctrlc_handler);
		lineSize = getline(&line, &len, stdin);
		if (lineSize == EOF || lineSize == -1)
			return (ctrld_handler(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		newline = _realloc(line);
		if (newline == NULL)
		{
			free(line);
			return (0);
		}
		t_array = tokenize(newline);
		if (t_array == NULL)
		{
			free(line);
			free(newline);
			return (0);
		}
		execute_cmd(t_array, env, av, line, newline, cmdnum);
		free_all(line, newline, t_array);
	}
}

/**
 *tokenize - splits a line into tokens and stores into a char array
 *@line: the line string to split
 *
 *Return: the array of strings
 */
char **tokenize(char *line)
{
	int i = 0;
	int t_count = 0;
	char **t_array;
	char *token, *t_copy;

	if (line == NULL)
		return (NULL);
	while (*(line + i) != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'
				       || line[i + 1] == '\t'))
			t_count++;
		i++;
	}

	i = 0;
	t_array = malloc(sizeof(char *) * (t_count + 1));
	if (t_array == NULL)
		return (NULL);
	token = strtok(line, DELIMITERS);
	while (token != NULL)
	{
		t_copy = _strdup(token);
		if (t_copy == NULL)
		{
			free(t_array);
			return (NULL);
		}
		*(t_array + i) = t_copy;
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	*(t_array + i) = NULL;
	return (t_array);
}
