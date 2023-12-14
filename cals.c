#include "monty.h"


/**
 * add_ops - This function adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void add_ops(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop_ops(stack, line_number);

	(*stack)->n = sum;
}



/**
 * sub_ops - This function subtracts the top element from
 * the second top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void sub_ops(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	pop_ops(stack, line_number);

	(*stack)->n = sub;
}



/**
 * mul_ops - Tis function multiplies the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void mul_ops(stack_t **stack, unsigned int line_number)
{
	int data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = (*stack)->n;
	pop_ops(stack, line_number);
	(*stack)->n *= data;
}



/**
 * div_ops - This function divides the second top element by the top
 * element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void div_ops(stack_t **stack, unsigned int line_number)
{
	int divisor;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	pop_ops(stack, line_number);

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= divisor;
}


/**
 * mod_ops - This function computes the remainder of the division of
 * the second top element by the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: Nothing
 */

void mod_ops(stack_t **stack, unsigned int line_number)
{
	int divisor;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	pop_ops(stack, line_number);

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= divisor;
}
