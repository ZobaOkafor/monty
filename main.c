#include "monty.h"

glo_var gee_var;

/**
 * main -Main function for the monty program
 * @argc: arguments count
 * @argv: opcode file
 *
 * Return: 0 Always
 */

int main(int argc, char **argv)
{
	size_t i = 0;
	instruct_func str;
	stack_t *stack = NULL;
	int checker, read, count = 1;
	char *line = NULL;

	gee_var.file = fopen(argv[1], "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (gee_var.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &i, gee_var.file)) != -1)
	{
		line = parse_line(line, &stack, count);
		if (line == NULL || line[0] == '#')
		{
			count++;
			continue;
		}
		str = get_ops(line);
		if (str == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, line);
			exit(EXIT_FAILURE);
		}
		str(&stack, count);
		count++;
	}
	free(line);
	checker = fclose(gee_var.file);
	if (checker == -1)
		exit(EXIT_FAILURE);
	free_stack(stack);
	return (0);
}
