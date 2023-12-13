#include "monty.h"


/**
 * push - push an element onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !is_numeric(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	push_value(stack, value);
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
 * is_numeric - check if a string represents a numeric value
 * @str: string to check
 * Return: 1 if numeric, 0 otherwise
 */

int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	for (; *str != '\0'; str++)
	{
		if (!isdigit(*str) && *str != '-')
			return (0);
	}
	return (1);
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


/**
 * push_value - push a value onto the stack
 * @stack: double pointer to the stack
 * @value: value to push
 */

void push_value(stack_t **stack, int value)
{
	stack_t *new_node;

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
