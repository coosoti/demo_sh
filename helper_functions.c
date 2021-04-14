#include "holberton.h"

/**
 *_strcmp - compares two strings
 *@s1: string 1
 *@s2: string 2
 *
 *Return: negative difference if s1 is less than s2, positive
 *difference if s1 is greater than s2, or 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	else if (*s1 > *s2)
		return ((int)(*s1 - *s2));
	else
		return ((int)(*s1 - *s2));
}
/**
 *_strdup - returns pointer to allocated space containing copy of string
 *@str: string that will be copied into the space
 *
 *Return: pointer to allocated space
 */
char *_strdup(char *str)
{
	int i = 0;
	int length = 0;
	char *string;

	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		length++;
		i++;
	}

	i = 0;
	string = malloc(sizeof(char) * length + 1);

	if (string == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		*(string + i) = *(str + i);
		i++;
	}
	*(string + i) = '\0';
	return (string);
}
/**
 *_strlen - calculates the length of a string
 *@buf: buffer to count length of strings
 *
 *Return: the length of the string
 */
int _strlen(char *buf)
{
	int i = 0;

	if (buf == NULL)
		return (-1);
	while (buf[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *str_concat - concatenates two strings
 *@s1: first string
 *@s2: second string to concatenate to first
 *
 *Return: pointer to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int lengths1 = 0;
	int lengths2 = 0;
	char *concatenate;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}

	lengths1 = _strlen(s1);
	lengths2 = _strlen(s2);

	concatenate = malloc(sizeof(char) * (lengths1 + lengths2 + 1));
	if (concatenate == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (_concat(concatenate, s1, s2));
}
/**
 *_concat - concatenates two strings
 *@concatenate: memory space to concatenate the strings
 *@s1: string 1
 *@s2: string 2
 *
 *Return: pointer to concatenated space
 */
char *_concat(char *concatenate, char *s1, char *s2)
{
	int concatcounter = 0;
	int stringcounter = 0;

	while (*(s1 + stringcounter) != '\0')
	{
		*(concatenate + concatcounter) = *(s1 + stringcounter);
		concatcounter++;
		stringcounter++;
	}

	stringcounter = 0;
	while (*(s2 + stringcounter) != '\0')
	{
		*(concatenate + concatcounter) = *(s2 + stringcounter);
		concatcounter++;
		stringcounter++;
	}
	*(concatenate + concatcounter) = '\0';
	return (concatenate);
}
