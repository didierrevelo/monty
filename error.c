#include "monty.h"
/**
 * err_ex - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void err_ex(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}
