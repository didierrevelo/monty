#include "monty.h"
/**
 * rfile - reads a bytecode file and runs commands
 * @fname: pathname to file
 * @stack: pointer to the top of the stack
 *
 */
void rfile(char *fname, stack_t **stack)
{
	char *buf = NULL;
	char *line;
	size_t i = 0;
	int l_count = 1;
	instruct_f s;
	int check;
	int read;
	FILE *file = fopen(fname, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&buf, &i, file)) != -1)
	{
		line = get_line(buf);
		if (line == NULL || line[0] == '#')
		{
			l_count++;
			continue;
		}
		s = get_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, l_count);
		l_count++;
	}
	free(buf);
	check = fclose(file);
	if (check == -1)
		exit(EXIT_FAILURE);
}
/**
 * get_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_f get_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * get_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *get_line(char *line)
{
	char *opc;

	opc = strtok(line, "\n ");
	if (opc == NULL)
		return (NULL);
	return (opc);
}
