#include"monty.h"
/**
 * delete_dnodeint_at_index - deletes the node at index.
 * @head: list.
 * @index: index of the list.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *aux;
	unsigned int runner;

	if (head == NULL || *head == NULL)
		return (-1);

	aux = *head;
	if (index == 0)
	{
		*head = aux->next;
		if (aux->next != NULL)
			(*head)->prev = NULL;
		free(aux);
		return (1);
	}
	for (runner = 0; aux != NULL; runner++)
	{
		if (runner == index)
		{
			if (aux->next != NULL)
				aux->next->prev = aux->prev;
			if (aux->prev != NULL)
				aux->prev->next = aux->next;
			free(aux);
			return (1);
		}
		aux = aux->next;
	}
	return (-1);
}
