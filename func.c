#include "monty.h"
/**
 * add_int - add
 *
 * @head: Data type
 *
 * @n: Data type
 *
 * Return: ptr
 */
stack_t *add_int(stack_t **head, const int n)
{
	stack_t *mem;

	mem = malloc(sizeof(stack_t));
	if (!mem)
	{
		return (NULL);
	}
	if (!*head)
	{
		mem->n = n;
		mem->next = NULL;
		mem->prev = NULL;
		*head = mem;
		return (*head);
	}
	(*head)->prev = mem;
	mem->n = n;
	mem->next = *head;
	mem->prev = NULL;
	*head = mem;
	return (*head);
}
