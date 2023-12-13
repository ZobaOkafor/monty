#define _POSIX_C_SOURCE 200809L

#include "monty.h"

/**
 * execute_opcode - execute
 * @stack: stack
 * @line_number: number
 * @line: pointer
 */

void execute_opcode(stack_t **stack, unsigned int line_number, char *line)
{
    char *opcode, *arg;

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
            exit(EXIT_FAILURE);
        }
        push(stack, line_number, atoi(arg));
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        free_stack(*stack);
        free(line);
        exit(EXIT_FAILURE);
    }
}


/**
 * main - check code
 * @argc: arguments count
 * @argv: arguments array
 *
 * Return: 0 Always
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_opcode(&stack, line_number, line);
	}

	free_stack(stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
