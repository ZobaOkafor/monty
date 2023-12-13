#include "monty.h"


/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: argument array
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0;
	char *content = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&content, &size, file) > 0)
	{
		line_number++;

		execute(content, &stack, line_number, file);

		free(content);
		content = NULL;
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
