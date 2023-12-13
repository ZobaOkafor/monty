#include "monty.h"

/**
 * addnode - Add a new node to the stack
 * @stack: Pointer to the head of the stack
 * @data: Data to be stored in the new node
 *
 * Return: Newly created node
 */

stack_t *addnode(stack_t **stack, int data)
{
	stack_t *new_node;

	new_node  = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	return (new_node);
}

