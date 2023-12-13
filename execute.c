#include "monty.h"

/**
 * execute - This function executes the opcode
 * @content: line content
 * @stack: pointer to the head of the stack
 * @line_number: line_counter
 * @file: pointer to the monty file
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
	char *code;
	unsigned int i = 0;

	code = strtok(content, " \n\t");
	if (code && code[0] == '#')
		return (0);
	
	/*arg = strtok(NULL, " \n\t");*/
	while (insts[i].opcode && code)
	{
		if (strcmp(code, insts[i].opcode) == 0)
		{
			insts[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (code && insts[i].opcode == NULL)
	{
		dprintf(2, "L%d: unknown instruction %s\n", line_number, code);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
