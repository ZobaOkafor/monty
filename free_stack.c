#include "monty.h"

/**
 * free_stack - Free the memory used by the stack
 * @stack: Pointer to the head of the stack
 *
 * Return: No return value
 */

void free_stack(Stack *stack)
{
	Stack *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
