#include "monty.h"

/**
 * execute - This function executes the opcode
 * @content: line content
 * @stack: pointer to the head of the stack
 * @line_number: line_counter
 *
 * Return: no return
 */

int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t insts[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *opcode;
	unsigned int i = 0;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	
	while (insts[i].opcode && opcode)
	{
		if (strcmp(opcode, insts[i].opcode) == 0)
		{
			insts[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (opcode && insts[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
