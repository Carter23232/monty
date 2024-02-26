#include "monty.h"
/**
 * push - push number to stack
 * @stack: the stack
 * @line_number: line of command
 */
void push(stack_t **stack, unsigned int line_number)
{
	if(!add_dnodeint(stack, number))
	{
		fprintf(stderr, "L<%d>: unknown instruction <opcode>", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * print - prints  stack
 * @stack: the stack
 * @line_number: line of command
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stk(*stack);
}

