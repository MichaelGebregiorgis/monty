#include "monty.h"
/**
 * push - push int
 *
 * @stk: Data type
 *
 * @line_num: Data type
 */
void push(stack_t **stk, unsigned int line_num)
{
	stack_t *mem;
	char *argt;
	int push_arg = 0;

	mem = malloc(sizeof(stack_t));
	if (!mem)
	{
		printf("Error: malloc failed\n");
		error_exit(stk);
	}

	argt = strtok(NULL, "\n");
	if (isnum(argt) == 1 && argt)
	{
		push_arg = atoi(argt);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_num);
		error_exit(stk);
	}

	if (flag == 1)
	{
		add_end(stk, push_arg);
	}

	if (flag == 0)
	{
		add_int(stk, push_arg);
	}

}
/**
 * pall - print
 *
 * @stk: Data type
 *
 * @line_num: Data type
 */
void pall(stack_t **stk, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *runr;

	runr = *stk;
	while (runr != NULL)
	{
		printf("%d\n", runr->n);
		runr = runr->next;
	}
}
/**
 * pint - print int
 *
 * @stk: Data type
 *
 * @line_num: Data type
 *
 */
void pint(stack_t **stk, unsigned int line_num)
{
	stack_t *runr;

	runr = *stk;
	if (runr == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		error_exit(stk);
	}
	printf("%d\n", runr->n);
}
/**
 * swap - swap stack
 *
 * @stk: Data type
 *
 * @line_num: Data type
 *
 */
void swap(stack_t **stk, unsigned int line_num)
{
	stack_t *runr;
	int temp;

	runr = *stk;
	if (!runr || !runr->next)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		error_exit(stk);
	}
	temp = runr->n;
	runr->n = runr->next->n;
	runr->next->n = temp;
}
/**
 * pop - delete
 *
 * @stk: Data type
 *
 * @line_num: Data type
 */
void pop(stack_t **stk, unsigned int line_num)
{
	if (!*stk)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		error_exit(stk);
	}
	del_at_index(stk, 0);
}
