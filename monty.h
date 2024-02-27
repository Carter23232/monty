#ifndef MONTY_H
#define MONTY_H

#include "stdio.h"
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



typedef struct prompt_s
{
	char *cont_per_line;
	char **tokened;
	unsigned  int line_no;
	size_t len;
} prompt_t;

#define PROMPT_INIT \
{NULL, NULL, 1, 0}

typedef struct parser_s
{
	int success;
	int value;
	int is_converted;
	char **str;
}parser_t;

extern parser_t parser[];
/**MAIN_FUNCTIONS**/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
/**DEPENDENCIES*/
/**list**/
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_stk(const stack_t *h);
size_t print_top(const stack_t *h);
size_t dlen(const stack_t *h);
stack_t *add_anypos(stack_t **head, unsigned int idx, const int n);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void _swapp(stack_t **h);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_stack(stack_t *head);
int is_comment(const char *str);


/**std_util**/
char **token(char ***sorted_array, char *buffer, char key);
char *_strcpy(char *dest, const char *src);
void free_str_arr(char **arr);
char *removeSpacesFromStr(char *string);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int trailing_space(char *str);
char *removeNewlineFromStr(char *string);
int _atoi(const char *str);
#endif
