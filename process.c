#include "monty.h"


/**
 * process_line - handles file processsing
 * @line: line
 * @line_number: number
 * @stack: stack
 */

void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	FILE *file = NULL;
	int found = 0;
	char *arg, *opcode;
	size_t i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL} };

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE); } }
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			found = 1;
			break; } }
	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE); }
}
