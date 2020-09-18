#include "monty.h"
/**
 * free_dlistint - this function free a list_t list
 * @head: values
 */
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
