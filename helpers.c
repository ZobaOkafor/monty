#include "monty.h"


/**
 * parse_line - This function parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 *
 * Return: returns the opcode or NULL on failure
 */

char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *args;

	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		args = strtok(NULL, "\n ");
		if (isnumber(args) == 1 && args != NULL)
		{
			gee_var.arg = atoi(args);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}



/**
 * get_ops -  This function checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a functions, or NULL on failure
 */

instruct_func get_ops(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push_ops},
		{"pall", pall_ops},
		{"pint", pint_ops},
		{"pop", pop_ops},
		{"swap", swap_ops},
		{"add", add_ops},
		{"nop", nop_ops},
		{"sub", sub_ops},
		{"mul", mul_ops},
		{"div", div_ops},
		{"mod", mod_ops},
		{"pchar", pchar_ops},
		{"pstr", pstr_ops},
		{"rotl", rotl_ops},
		{"rotr", rotr_ops},
		{NULL, NULL},
	};

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

