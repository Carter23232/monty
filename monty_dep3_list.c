#include "monty.h"
/**
 * add_ - adds first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
int add_(stack_t **h)
{
	int result = 0, i = 0;
	stack_t *cur = (*h);

	while (i < 2)
	{
		result += cur->n;
		cur = cur->next;
		i++;
	}
	return (result);
}

