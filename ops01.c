#include "monty.h"


/**
 * nop_ops - This function does nothing (No operation)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void nop_ops(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* No operation */
}



/**
 * pchar_ops - This function prints the ASCII value
 * of the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void pchar_ops(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}


	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}


/**
 * pstr_ops - This function prints the ASCII characters of the stack,
 * until a non-printable character is encountered,
 * or the stack is empty
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void pstr_ops(stack_t **stack, unsigned int line_number)
{
	int c = 0;
	stack_t *temp;

	(void)line_number;

	temp = *stack;

	while (temp)
	{
		c = temp->n;
		if (c == 0 || !isprint(c))
			break;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}
