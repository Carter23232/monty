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

/**
 * _add - add first 2 elements and replace them with result
 * @stack: the stack
 * @line_number: line of command
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int res, i = 0;

	if (*stack && dlen(*stack) >= 2)
	{
		res = add_(stack);
		while (i < 2)
		{
			delete_dnodeint_at_index(stack, 0);
			i++;
		}
		add_dnodeint(stack, res);
		parser->success = 1;
	}
	else
	{
		parser->success = 0;
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
