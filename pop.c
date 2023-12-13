#include "monty.h"


/**
 * pop - This function deletes data from the stack
 * @stack: stack head
 * @line_number: line counter
 *
 * Return: no return
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
