#include "monty.h"
/**
 * add_dnodeint - this function add a new node to doble linked list
 * @head: pointer to the head of the list
 * @n: number of return
 * Return: addres of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->n = n;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
		return (new);
	}
}
