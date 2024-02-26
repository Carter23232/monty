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
	char *line;
	char **tokened;
	unsigned  int line_no;
	int iscmd, value;
	size_t len;
} prompt_t;

#define PROMPT_INIT \
{NULL, NULL, 0, 0, 0, 0}

extern int number;
/**MAIN_FUNCTIONS**/
void push(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
int read_and_cp_file(char *file, prompt_t cmd[]);
/**DEPENDENCIES*/
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
stack_t *add_anypos(stack_t **head, unsigned int idx, const int n);
size_t dlen(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int _strlen(const char *s);
char *removeSpacesFromStr(char *string);
void free_str_arr(char **arr);
char *_strcpy(char *dest, const char *src);
void copy_file(const char **file, char **file_content);
char **token(char ***sorted_array, char *buffer, char key);
size_t print_stk(const stack_t *h);
int _strcmp(char *s1, char *s2);
void free_stack(stack_t *head);
#endif
