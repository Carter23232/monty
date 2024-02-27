#include "monty.h"
/**
 * is_comment - checks if a line is a comment
 * @str: string
 * Return: 1 for true and false ow
 */
int is_comment(const char *str)
{
	if (str && str[0] == '#')
		return (1);
	return (0);
}
