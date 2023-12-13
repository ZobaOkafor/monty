#include "monty.h"


/**
 * main - ccheck code
 * @argc: arguments count
 * @argv: argument array
 *
 * Return: 0 Always
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	/*instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};*/

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
		process_line(line, line_number, &stack);
	}
	free_stack(stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
