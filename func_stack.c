#include "monty.h"
int flag = 0;
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
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, "\n ");
	if (number(arg) == 1 && arg != NULL)
	{
		p_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (flag == 1)
	{
		add_dnodeint(stack, p_arg);
	}
	else
		add_dnodeint_end(stack, p_arg);
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *run;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	run = *stack;
	while (run != NULL)
	{
		fprintf(stdout, "%d\n", run->n);
		run = run->next;
	}
}
/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *run;

	run = *stack;
	if (run == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", run->n);
}

/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *run;
	int temp;

	run = *stack;
	if (run == NULL || run->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = run->n;
	run->n = run->next->n;
	run->next->n = temp;
}
