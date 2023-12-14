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
/**
 * del_at_index - delete
 *
 * @head: Data type
 *
 * @index: Data type
 *
 * Return: 1 / -1
 */
int del_at_index(stack_t **head, unsigned int index)
{
	stack_t *tempo;
	stack_t *tempo2;

	unsigned int inc;

	if (!*head)
		return (-1);

	tempo = *head;

	if (index == 0)
	{
		*head = tempo->next;
		if (tempo->next != NULL)
			tempo->next->prev = NULL;
		free(tempo);
		return (1);
	}
	inc = 0;
	while (inc < (index - 1))
	{
		if (tempo == NULL)
			return (-1);
		tempo = tempo->next;
		inc += 1;
	}
	tempo2 = (tempo->next)->next;

	if (tempo->next->next)
		tempo->next->next->prev = tempo;
	free(tempo->next);
	tempo->next = tempo2;

	return (1);
}
/**
 * add_end - end of list
 *
 * @head: Data type
 *
 * @n: Data type
 *
 * Return: ptr
 */
stack_t *add_end(stack_t **head, const int n)
{
	stack_t *temp = *head;
	stack_t *mode;

	mode = malloc(sizeof(stack_t));
	if (!mode)
		return (NULL);

	mode->n = n;

	if (!*head)
	{
		mode->next = NULL;
		mode->prev = NULL;
		*head = mode;
		return (mode);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = mode;
	mode->prev = temp;
	mode->next = NULL;
	return (mode);
}
/**
 * free_int - free a list
 *
 * @head: Data type
 */
void free_int(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
	}
}
