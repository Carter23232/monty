#include "monty.h"
void initializer(void);
parser_t parser[1];
/**
 * main - entry int to program
 * @argc : argument counter
 * @argv : array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	stack_t *stk = NULL;
	prompt_t cmd[] =  { PROMPT_INIT };
	FILE *monty_file;
	instruction_t spc[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", _swap}};
	size_t i = 0, spc_len = sizeof(spc) / sizeof(spc[0]);

	initializer();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((int)getline(&(cmd->cont_per_line), &cmd->len, monty_file) != -1)
	{
		if (!trailing_space(cmd->cont_per_line))
		{
			token(&cmd->tokened, cmd->cont_per_line, ' ');
			while (i < spc_len && parser->success == 0)
			{
				if (_strcmp(spc[i].opcode, cmd->tokened[0]) == 0)
				{
					parser->str = &cmd->tokened[1];
					spc[i].f(&stk, cmd->line_no);
				}
				else
					i++;
			}
			if (i == spc_len && !parser->success)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
					cmd->line_no, cmd->tokened[0]);
				exit(EXIT_FAILURE);
			}
			(*cmd->cont_per_line)++, cmd->line_no++, parser->success
			= 0, free_str_arr(cmd->tokened), i = 0;
		}
		else
			(*cmd->cont_per_line)++, cmd->line_no++;
	}
	fclose(monty_file), free(cmd->cont_per_line), free_stack(stk);
	return (0);
}
/**
 * initializer - initialise extern parser
 */
void initializer(void)
{
	parser->success = 0;
	parser->value = 0;
	parser->is_converted = 0;
	parser->str = NULL;
}
