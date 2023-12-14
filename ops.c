#include "monty.h"


/**
 * push_ops - This function pushes an integer onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void push_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = gee_var.arg;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pall_ops - This function prints all the elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void pall_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *items;

	(void)line_number;

	items = *stack;
	while (items != NULL)
	{
		printf("%d\n", items->n);
		items = items->next;
	}
}


/**
 * pint_ops - This function prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void pint_ops(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * pop_ops - This function removes the top element from the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void pop_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = top_node->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top_node);
}


/**
 * swap_ops - This function swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void swap_ops(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	top  = *stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
