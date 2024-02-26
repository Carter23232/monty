#include "monty.h"
/**
 * copy_file - copy content of file
 * @file: input cmd
 * @file_content: reference to environmental variables
 */

void copy_file(const char** file, char **file_content)
{
	int num_element = 0, i = 0;

	while (file[num_element] != NULL)
		num_element++;

	file_content = malloc(sizeof(char *) * (num_element + 1));

	if (file_content == NULL)
	{
		free(file_content);
		return;
	}
	while (file[i] != NULL)
	{
		file_content[i] = malloc(sizeof(char) * _strlen((char*)file[i]) + 1);
		if (file_content[i] != NULL)
			_strcpy(file_content[i], (char*)file[i]);
		i++;
	}
	file_content[i] = NULL;
}
/**
 * free_str_arr - free memory of array of strings
 * @arr: the array
 *
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
* _strcpy - Copy a string
* @dest: Destination value
* @src: Source value
*
* Return: the pointer to dest
*/
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
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