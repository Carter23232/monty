#include "monty.h"

/**
 * free_str_arr - free memory of array of strings
 * @arr: the array
 */
void free_str_arr(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

/**
 * _strcmp - compares s1 and s2
 * @s1: lhs
 * @s2 : rhs
 *
 * Return: returns copied string
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) == _strlen(s2))
	{
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
		}

	}
	else
		return (-1);
	return (0);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: input command
 * Return: A integer
 */
int _atoi(const char *str)
{
	int index = 0, no = 0, min = 1, mx = 0, len = _strlen(str);

	if (str == NULL)
	{
		parser->is_converted = 0;
		return (0);
	}

	while (str[index])
	{
		if (str[index] == 45)
		{
			min *= -1;
		}

		while (str[index] >= 48 && str[index] <= 57)
		{
			mx = 1;
			no = (no * 10) + (str[index] - '0');
			index++;
		}

		if (mx == 1)
			break;
		index++;
	}
	no *= min;
	if (index == len - 1)
	{
		parser->is_converted = 0;
		return (0);
	}
	parser->is_converted = 1;
	return (no);
}

/**
 * removeNewlineFromStr - removes trailing spaces from string
 * @string: input string
 * Return: an edited string
 */
char *removeNewlineFromStr(char *string)
{
	size_t  len = _strlen(string), i = 0, j = 0;

	removeSpacesFromStr(string);
	for (i = 0 ; i < len; i++)
	{
		if (string[0] == '\n')
		{
			for (i = 0; i < (len - 1); i++)
				string[i] = string[i + 1];
			string[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (string[i] == '\n' && string[i + 1] == '\n')
		{
			for (j = i; j < (len - 1); j++)
			{
				string[j] = string[j + 1];
			}
			string[j] = '\0';
			len--;
			i--;
		}
		else if (string[i] == '\n' && string[i + 1] == '\0')
			string[i] = '\0';
	}
	return (string);
}

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}
