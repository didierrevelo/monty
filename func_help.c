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

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_dnodeint_end - this function add a new node to doble linked list
 * @head: pointer to the head of th list
 * @n: number of return
 * Return: addres of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *tem = *head;

	new = malloc(sizeof(stack_t));
	if (new)
	{
		new->prev = NULL;
		new->n = n;
		if (!*head)
		{
			new->next = NULL;
			*head = new;
			return (new);
		}
		while (tem->next)
			tem = tem->next;
		tem->next = new;
		new->prev = tem;
		return (new);
	}
	return (NULL);
}

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
