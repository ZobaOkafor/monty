#include "monty.h"


/**
 * rotl_ops - This function rotates the stack to the left,
 * moving the top element to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void rotl_ops(stack_t **stack, unsigned int line_number)
{
	int data = 0;
	stack_t *items;

	(void)line_number;

	items = *stack;
	if (items && items->next)
	{
		data = items->n;

		while (items->next)
		{
			items->n = items->next->n;
			items = items->next;
		}

		items->n = data;
	}
}



/**
 * rotr_ops - This function rotates the stack to the right,
 * moving the bottom element to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void rotr_ops(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *items;

	(void)line_number;

	items = *stack;
	if (items && items->next)
	{
		while (items->next)
			items = items->next;

		data = items->n;

		while (items->prev)
		{
			items->n = items->prev->n;
			items = items->prev;
		}

		items->n = data;
	}
}
