#include "monty.h"


/**
 * push - push an element onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pall - print all values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * free_stack - free all elements of the stack
 * @stack: pointer to the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
