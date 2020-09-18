#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int p_arg;

	p_arg = 0;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		err_ex(stack);
	}

	arg = strtok(NULL, "\n ");
	if (number(arg) == 1 && arg != NULL)
	{
		p_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		err_ex(stack);
	}

	if (flag == 1)
	{
		add_dnodeint_end(stack, p_arg);
	}

	if (flag == 0)
	{
		add_dnodeint(stack, p_arg);
	}

}
/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *run;

	run = *stack;
	while (run != NULL)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}