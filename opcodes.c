#include "monty.h"


/**
 * pint - This function prints the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line counter
 *
 * Return: no return
 */

void pint(stack_t **stack, unsigned int line_number)
{
	FILE *file = NULL;
	char *content = NULL;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: Line_number: Can't pop an empty stack\n", line_number);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
