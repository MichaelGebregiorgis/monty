#define _GNU_SOURCE
#include "monty.h"
/**
 * file_read - reads file
 *
 * @filename: Data type
 *
 * @stk: Data type
 */
void file_read(char *filename, stack_t **stk)
{
	char *bfr = NULL;
	char *ln;
	inst_func s;
	size_t v = 0;
	int chk;
	int rd;
	int ln_cnt = 1;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stk);
	}
	rd = getline(&bfr, &v, file);
	while ((rd = getline(&bfr, &v, file)) != -1)
	{
		ln = line_prse(bfr);
		if (ln == NULL || ln[0] == '#')
		{
			ln_cnt += 1;
			continue;
		}
		s = get_op(ln);
		if (!s)
		{
			printf("L%d: unknown instruction %s\n", ln_cnt, ln);
			error_exit(stk);
		}
		s(stk, ln_cnt);
		ln_cnt += 1;
	}
	free(bfr);
	chk = fclose(file);
	if (chk == -1)
		exit(-1);
}
/**
 * line_prse - parse
 *
 * @line: Data type
 *
 * Return: 0
 */
char *line_prse(char *line)
{
	char *cd = strtok(line, "\n ");

	if (!cd)
	{
		return (NULL);
	}
	return (cd);
}
/**
 * get_op - opcheck
 *
 * @str: Data type
 *
 * Return: func
 */

inst_func get_op(char *str)
{
	int inc = 0;

	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL},
	};
	while (inst[inc].f != NULL && strcmp(inst[inc].opcode, str) != 0)
	{
		inc += 1;
	}
	return (inst[inc].f);
}
