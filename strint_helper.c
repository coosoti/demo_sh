#include "holberton.h"

/**
 *tens_places - finds the multiplication factor of tens
 *@i: the index of where a number starts in the string
 *@s: the string pointer
 *
 *Return: the tens multiplier
 */
int tens_places(int i, char *s)
{
	double tens = 1;

	while (s[i] >= '0' && s[i] <= '9')
	{
		tens *= 10;
		i++;
	}
	tens /= 10;
	return ((int) tens);
}
/**
 *_atoi - converts a string to an integer
 *@s: string to convert to integer
 *
 *Return: the integer value of the converted string
 */
int _atoi(char *s)
{
	int i = 0, j = 0;
	int tens = 1;
	unsigned int integer = 0;
	int is_neg = 0;
	int neg_nums = 0;
	int pos_nums = 0;

	while (s[j] != '\0')
	{
		if (s[j] > '9' || s[j] < '0')
			return (-1);
		j++;
	}
	while ((s[i] > '9' || s[i] < '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			neg_nums++;
		if (s[i] == '+')
			pos_nums++;
		i++;
	}
	if (s[i] == '\0')
		return (0);

	if ((neg_nums % 2) != 0)
		is_neg = 1;

	tens = tens_places(i, s);
	while (s[i] >= '0' && s[i] <= '9')
	{
		integer += ((s[i] - '0') * tens);
		tens /= 10;
		i++;
	}
	if (is_neg == 1)
		integer *= -1;

	return ((int) integer);
}

/**
 *print_int - prints an integer
 *@num: the number to turn into a string
 *
 *Return: number of characters printed to stdout
 */
char *print_int(int num)
{
	int tens = 1;
	int i = 0;
	int tensint = num;
	char *integer;

	integer = malloc(33);
	if (integer == NULL)
		return (NULL);
	if (num == 0)
	{
		integer[i] = 0 + '0';
		return (integer);
	}
	num = num / 10;

	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		integer[i] = (tensint / tens) + '0';
		tensint = tensint % tens;
		tens /= 10;
		i++;
	}
	integer[i] = '\0';
	return (integer);
}
