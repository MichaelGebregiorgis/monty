#include "monty.h"
/**
 * main - monty program
 *
 * @ac: Data type
 *
 * @av: Data type
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stk;

	stk = NULL;
	if (ac != 2)
	{
		printf("USAGE: MONTY FILE\n");
		error_exit(&stk);
	}
	file_read(av[1], &stk);
	free_int(stk);
	return (0);
}
