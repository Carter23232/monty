#include "monty.h"
/**
 * get_num_of_words - calculates the number of words in a string
 * @buffer: input string
 * @key: delimeter
 * Return: number of words
 */
int get_num_of_words(char *buffer, char key)
{
	int n_of_words = 1;

	if (buffer == NULL)
		return (0);
	while (*buffer != '\0')
	{
		if (*buffer == key)
		{
			n_of_words++;
		}
		buffer++;
	}
	return (n_of_words);
}
/**
 * len_per_word - calculates the number characters in a word
 * @str: input string
 * @pos: current position of iterator
 * @key: delimeter
 * Return: number of characters in a word
 */
int len_per_word(const char *str, size_t pos, char key)
{
	int len = 0;

	while (str[pos] != '\0')
	{
		if (str[pos] != key)
			len++;
		pos++;
		if (str[pos] == key)
			break;
	}
	return (len);
}
/**
 * token - splits a string into tokens(array of words)
 * @sorted_array: variable to store tokenized array
 * @buffer: input string
 * @key: delimeter
 * Return: array of token.
 */
char **token(char ***sorted_array, char *buffer, char key)
{
	char *mem_E_msg = "memory allocation failed\n";
	int index_array = 0, no_words = get_num_of_words(buffer, key);
	size_t i, buf_len, sorted_index = 0, len;

	if (buffer == NULL && *sorted_array != NULL)
		return (NULL);
	buf_len = _strlen(buffer);
	(*sorted_array) = malloc(sizeof(char *) * (no_words + 1));
	if ((*sorted_array)  == NULL)
		fprintf(stderr, "%s\n", mem_E_msg);
	len = len_per_word(buffer, 0, key);
	for (i = 0; i < buf_len; i++)
	{
		(*sorted_array)[index_array] = malloc((sizeof(char) * (len + 1)));
		if ((*sorted_array)[index_array] == NULL)
		{
			fprintf(stderr, "%s\n", mem_E_msg);
			free_str_arr(*sorted_array);
			return NULL;
		}
		while ((buffer)[i] != key && (buffer)[i] != '\0')
		{
			if ((*sorted_array)[index_array] != NULL && sorted_index < len)
			{
				(*sorted_array)[index_array][sorted_index] = (buffer)[i];
				sorted_index++, i++;
			}
			if (sorted_index == len)
				(*sorted_array)[index_array][len] = '\0';
		}
		len = len_per_word(buffer, i, key), sorted_index = 0, index_array++;
	}
	(*sorted_array)[no_words] = NULL;
	return (*sorted_array);
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

/**
 * removeSpacesFromStr - removes trailing spaces from string
 * @string: input string
 * Return: an edited string
 */
char *removeSpacesFromStr(char *string)
{
	size_t  len = _strlen(string), i = 0, j = 0;

	for (i = 0 ; i < len; i++)
	{
		if (string[0] == ' ')
		{
			for (i = 0; i < (len - 1); i++)
				string[i] = string[i + 1];
			string[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (string[i] == ' ' && string[i + 1] == ' ')
		{
			for (j = i; j < (len - 1); j++)
			{
				string[j] = string[j + 1];
			}
			string[j] = '\0';
			len--;
			i--;
		}
		else if (string[i] == ' ' && string[i + 1] == '\0')
			string[i] = '\0';
	}
	return (string);
}
/**
 * trailing_space - handle empty parameters
 * @str: input stream
 * Return: 1 if succeed and 0 otherwise
 */

int trailing_space(char *str)
{
	size_t i = 0;
	int is_space = 0;

	if (str == NULL || _strlen(str) == 0)
		return (1);

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n')
			is_space++;
		if (str[i] == '\n' && str[i + 1] != '\0')
			is_space++;
		i++;
	}
	if (is_space == _strlen(str))
		return (1);
	return (0);
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