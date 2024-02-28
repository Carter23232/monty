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

/**
 * _swp3- swaps first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
void _swp3(stack_t **h)
{
	int temp = (*h)->n;
	(*h)->n = (*h)->next->next->n;
	(*h)->next->next->n = temp;
}