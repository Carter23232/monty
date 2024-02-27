#include "monty.h"
/**
 * rotl - rotates, first becomes last and last becomes first
 * @stack: the stack
 * @line_number: line of command
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *rev = NULL, *cur = *stack;

	(void)line_number;
	if(*stack)
	{
		while (cur)
		{
			add_dnodeint(&rev, cur->n);
			cur = cur->next;
		}
		free_stack(*stack);
		*stack = rev;
	}
	parser->success = 1;
}