#include "monty.h"

/**
 * insert_dnodeint_at_index - insert node at a given idx of doubly linked list
 * @h: head of list
 * @idx: index to insert
 * @n:number
 * Return: address of the new node, or NULL
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	size_t len = dlen(*h);

	if (idx > len)
		return (NULL);
	if (idx == 0 || len == 0)
		return (add_dnodeint(h, n));
	if (idx == len)
		return (add_dnodeint_end(h, n));
	return (add_anypos(h, idx, n));
}

/**
 * add_anypos -  insert node at a given index of doubly linked list
 * @head: head of list
 * @idx: index to insert
 * @n:number
 * Return: address of the new node, or NULL
 */
stack_t *add_anypos(stack_t **head, unsigned int idx, const int n)
{
	stack_t *n_data, *cur = *head, *temp;
	unsigned int index = 0;

	if (!*head)
		return (NULL);

	n_data = malloc(sizeof(stack_t));
	if (!n_data)
		return (NULL);
	n_data->n = n;
	while (cur)
	{
		if (index == idx - 1)
		{
			temp = cur->next;
			cur->next = n_data;
			n_data->prev = cur;
			n_data->next = temp;
			temp->prev = n_data;
		}
		cur = cur->next;
		index++;
	}
	return (n_data);
}

/**
 * dlen - doubly linked list len
 * @h: head of list
 * Return: 0 if none or len
 */
size_t dlen(const stack_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}

/**
* delete_dnodeint_at_index - delete node in doubly linked list
* @head: pointer to the head
* @index: nth element to del
* Return: 1 if successful or -1 otherwise
*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *cur = *head, *temp;
	unsigned int counter = 0;
	size_t len = dlen(*head);

	if (index > len - 1 || !(*head))
		return (-1);
	while (cur)
	{
		if (index == 0)
		{
			*head = cur->next;
			if (*head)
				(*head)->prev = NULL;
			free(cur);
			break;
		}

		else if (counter == index - 1)
		{
			temp = cur->next;
			cur->next = temp->next;
			if (temp->next)
				temp->next->prev = cur;
			free(temp);
			break;
		}
		else if (index == len - 1)
		{
			cur->prev->next = NULL;
			free(cur);
			break;

		}
		cur = cur->next;
		counter++;
	}
	return (1);
}

/**
 * print_stk - print doubly linked list
 * @h: head of list
 * Return: 0 if none or len
 */
size_t print_stk(const stack_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}
	return (len);
}
