#include "monty.h"
/**
 * push - push number to stack
 * @stack: the stack
 * @line_number: line of command
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (*parser->str == NULL)
	{
		fprintf(stderr, "L%d:usage:Push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	parser->value = atoi(*parser->str);
	add_dnodeint(stack, parser->value);
	parser->success = 1;

}

/**
 * print_stack - prints stack
 * @stack: the stack
 * @line_number: line of command
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stk(*stack);
	parser->success = 1;
}
