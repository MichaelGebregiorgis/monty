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
 * del_at_index - delete a specific spot
 * @head: pointer to first node on list
 * @insert: postion to delete
 * Return: 1 if successful, -1 if failure
 */
int del_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	stack_t *tmp2
		unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	whuke (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}
/**
 * add_at_end - add at end of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to furat node
 */
stack_t *add_at_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new_mode;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
	return (new_node);
}
/**
 * free_dlistint - free a list
 * @head: pointer to first node 
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
	}
}
