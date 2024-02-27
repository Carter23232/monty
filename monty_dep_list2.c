#include "monty.h"
/**
 * add_dnodeint - add node to the beginning of doubly linked list
 * @head: head of list
 * @n: data to add to list
 * Return: address or NUll
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *n_data;

	n_data = malloc(sizeof(stack_t));
	if (!n_data)
	{
		free(n_data);
		return (NULL);
	}
	n_data->n = n;
	n_data->prev = NULL;
	n_data->next = *head;
	if (*head)
		(*head)->prev = n_data;
	*head = n_data;
	return (*head);
}

/**
 * add_dnodeint_end - add node to the end of doubly linked list
 * @head: head of list
 * @n: data to add to list
 * Return: address or NUll
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *n_data, *last = *head;

	n_data = malloc(sizeof(stack_t));
	if (!n_data)
		return (NULL);
	n_data->next = NULL;
	n_data->n = n;
	if (!*head)
	{
		n_data->prev = NULL;
		*head = n_data;
		return (*head);
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = n_data;
		n_data->prev = last;
	}
	return (n_data);
}

/**
 * free_stack - free doubly linked list
 * @head: head of list
 */
void free_stack(stack_t *head)
{
	stack_t *cur;

	while (head)
	{
		cur = head;
		head = head->next;
		free(cur);
	}
}

/**
 * print_top - print element in doubly linked list
 * @h: head of list
 * Return: 0 if none or len
 */
size_t print_top(const stack_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);
	return (1);
}

/**
 * _swapp - swaps first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
void _swapp(stack_t **h)
{
	 int temp = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = temp;
}
