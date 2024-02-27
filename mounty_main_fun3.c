#include "monty.h"
/**
 * _mul - add first 2 elements and replace them with result
 * @stack: the stack
 * @line_number: line of command
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int res, i = 0;

	if (*stack && dlen(*stack) >= 2)
	{
		res = (*stack)->next->n * (*stack)->n;
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - add first 2 elements and replace them with result
 * @stack: the stack
 * @line_number: line of command
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int res, i = 0;

	if (*stack && (*stack)->n == 0)
	{
		parser->success = 0;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);

	}
	if (dlen(*stack) >= 2)
	{
		res = (*stack)->next->n % (*stack)->n;
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
