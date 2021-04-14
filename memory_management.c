#include "holberton.h"

/**
 *_reallocchar - reallocates memory for char
 *@ptr: a pointer to an array
 *
 *Return: pointer to new memory
 */
char *_reallocchar(char *ptr)
{
	int i = 0;
	char *newptr;

	if (ptr == NULL)
		return (NULL);

	while (*(ptr + i) != '\n')
		i++;

	newptr = malloc(sizeof(char) * i + 1);
	if (newptr == NULL)
		return (NULL);
	i = 0;
	while (*(ptr + i) != '\n')
	{
		*(newptr + i) = *(ptr + i);
		i++;
	}
	*(newptr + i) = '\0';
	return (newptr);
}

/**
 *free_all - frees all of the variables used
 *@line: the original line entered by user
 *@newline: line truncated to remove new line char
 *@tokenarray: array of token strings
 *
 *Return: void
 */
void free_all(char *line, char *newline, char **tokenarray)
{
	free_tokens(tokenarray);
	free(line);
	free(newline);
	free(tokenarray);
}
/**
 *free_list - frees a list_t list
 *@head: head of the linked list
 *
 *Return: void
 */
void free_list(path_t *head)
{
	path_t *nextnode;

	while (head != NULL)
	{
		nextnode = head->next;
		free(head->directory);
		free(head);
		head = nextnode;
	}
}
/**
 *free_tokens - frees the tokens in the tokenarray
 *@tokenarray: array of tokens
 *
 *Return: void
 */
void free_tokens(char **tokenarray)
{
	int i = 0;

	while (tokenarray[i] != NULL)
	{
		free(tokenarray[i]);
		i++;
	}
	free(tokenarray[i]);
}
