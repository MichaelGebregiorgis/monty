#include "monty.h"
/**
 * add - add on stack
 *
 * @stk: Data type
 *
 * @line_num: Data type
 */
void add(stack_t **stk, unsigned int line_num)
{
	if (!*stk || (*stk)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		error_exit(stk);
	}
	(*stk)->next->n += (*stk)->n;
	pop(stk, line_num);
}

/**
 * error_exit - free stack
 *
 * @stk: Data type
 */
void error_exit(stack_t **stk)
{
	if (*stk)
	{
		free_int(*stk);
	}
	exit(EXIT_FAILURE);
}

/**
 * isnum - check for num
 *
 * @str: Data type
 *
 * Return: 1/0
 */
int isnum(char *str)
{
	unsignedint inc = 0;

	if (!str)
	{
		return (0);
	}
	for (; str[i]; inc++)
	{
		if (str[0] == '-')
		{
			inc += 1;
			continue;
		}
		if (!isdigit(str[inc]))
			return (0);
	}
	return (1);
}

/**
 * nop - nothingness
 *
 * @stk: Data type
 *
 * @line_num: Data type
 */
void nop(__attribute__ ((unused))stack_t **stk,
	__attribute__ ((unused))unsigned int line_num)
{
	;
}
