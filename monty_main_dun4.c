#include "monty.h"
/**
 * rotl - rotates, first becomes last and last becomes first
 * @stack: the stack
 * @line_number: line of command
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack, *cur1 = *stack, *new = NULL;
	int *arr = NULL;
	int value[4], i = 0, k = 0,  j = 0, len;

	(void)line_number;
	if (*stack)
	{
		len = (int)dlen(*stack);
		arr = (int *)malloc(sizeof(int) * (len + 1));
		if (!arr)
			return;
		value[0] = (*stack)->n, value[1] = (*stack)->next->n;
		while (cur)
		{
			if (cur->next && cur->next->next == NULL)
				value[2] = cur->n, value[3] = cur->next->n;
			cur = cur->next;
		}

		while (cur1)
		{
			if (k < 2)
				arr[i] = value[k], k++;
			if (i >=  2 && i <= len - 3)
			{
				arr[i] = cur1->n;
			}
			else if (i >= len - 2 && i < len && k < 4)
				arr[i] = value[k], k++;
			cur1 = cur1->next, i++;
		}
		arr[len] = '\0';
		free_stack(*stack);
		while (j < len)
			add_dnodeint(&new, arr[j]), j++;
		*stack = new;
	}
	parser->success = 1;
	free(arr);
}
