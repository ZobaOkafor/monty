#include "monty.h"

/**
 * push - This function adds a new node to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * @arg: argument for the push operation
 *
 * Return: No return value
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i;
	int n = 0;
	char *arg = NULL;
	/*FILE *file = NULL;*/

	if (!arg || (*arg == '-' && !arg[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = (*arg == '-'); arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = n * 10 + (arg[i] - '0');
	}

	addnode(stack, n);
	/*file = fopen(arg[1], "a");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open the file\n");
		exit(EXIT_FAILURE);
	}

	fclose(file);*/
}


/**
 * pall - s function prints the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: no return
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

