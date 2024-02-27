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
 * div_ - divide first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
int div_(stack_t **h)
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
 * mul_ - multiply first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
int mul_(stack_t **h)
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
 * mod_ - mod first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
int mod_(stack_t **h)
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
 * sub_ - subtract first 2 element
 * @h: head of list
 * Return: 0 if none or 1
 */
int sub_(stack_t **h)
{
	return ((*h)->next->n - (*h)->n);
}
