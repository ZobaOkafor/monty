#include "monty.h"


/**
 * stack - prints the top
 * @stack: stack head
 * @line_number: line counter
 *
 * Return: no return
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	int value  = 0;
}


/**
 * add_node - Add a new node to the stack
 * @stack: Pointer to the head of the stack
 * @n: Data to be stored in the new node
 *
 * Return: Newly created node
 */

void add_node(stack_t **stack, int n)
{
	stack_t *new_node;
	stack_t *data;

	data = *stack;
	new_node  = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (data)
		data->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}


/**
 * queue - prints the top
 * @stack: stack head
 * @line_number: line counter
 *
 * Return: no return
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	int value = 1;
}

/**
 * add_queue - This functions adds a node from the rear of a queue
 * @stack: head of the stack
 * @n: new_value to add
 *
 * Return: no return
 */

void add_queue(stack_t **stack, int n)
{
	stack_t *new_node, *data;

	data = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (data)
	{
		while (data->next)
			data = data->next;
	}
	if (!data)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		data->next = new_node;
		new_node->prev = data;
	}
}
