#include "monty.h"
/**
 * main - entry int to program
 * @argc : argument counter
 * @argv : array of arguments
 * Return: 0 on success
 */
int number;

int main(int argc, char **argv)
{
	int i = 0;
	stack_t *stk = NULL;
	prompt_t cmd[] =  { PROMPT_INIT };
	FILE *monty_file;

	instruction_t spc[] = {{"push", push}, {"pall", print_stack}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&cmd->line, &cmd->len, monty_file) != -1)
	{
		token(&cmd->tokened, removeSpacesFromStr(cmd->line), ' ');
		while (i < sizeof(spc) && cmd->iscmd == 0)
		{
			if (_strcmp(cmd->tokened[0], spc[i].opcode) == 0)
			{
				if (cmd->tokened[1])
					number = atoi(cmd->tokened[1]);
				spc[i].f(&stk, cmd->line_no);
				cmd->iscmd = 1;
			}
			else
				i++;
		}
		if (i == sizeof(spc) && !cmd->iscmd)
		{
			fprintf(stderr, "L<%d>: unknown instruction <opcode>", cmd->line_no);
			exit(EXIT_FAILURE);
		}
		(*cmd->line)++, cmd->line_no++, cmd->iscmd = 0, free_str_arr(cmd->tokened);
	}
	fclose(monty_file);
	free(cmd->line);
	free_stack(stk);
	return (0);
}

