#include "monty.h"
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
		res = (*stack)->next->n + (*stack)->n;
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothing
 * @stack: the stack
 * @line_number: line of command
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
	parser->success = 1;
}
/**
 * _sub - sub first 2 elements and replace them with result
 * @stack: the stack
 * @line_number: line of command
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int res, i = 0;

	if (*stack && dlen(*stack) >= 2)
	{
		res = (*stack)->next->n - (*stack)->n;
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * _div - div first 2 elements and replace them with result
 * @stack: the stack
 * @line_number: line of command
 */
void _div(stack_t **stack, unsigned int line_number)
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
		res = (*stack)->next->n / (*stack)->n;
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
