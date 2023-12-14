#include "monty.h"


/**
 * push - This function adds an elemnt to the stack
 * @value: value to add
 * @line_number: line counter
 *
 * Return: no return
 */

void push(int value, int line_number)
{
	if (stack.top >= STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack.top++;
	stack.stack[stack.top] = value;
}


/**
 * pall - This function prints the contents of the stack
 *
 * Return: no return
 */

void pall(void)
{
	int i;

	for (i = stack.top; i >= 0; i--)
	{
		if (stack.stack[i] != 0)
			printf("%d\n", stack.stack[i]);
	}
}


/**
 * pint - This function prints the top value of the stack
 * @line_number: line counter
 *
 * Return: no return
 */

void pint(int line_number)
{
	if (stack.top < 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack.stack[stack.top]);
}


/**
 * pop - This function removes an elemnet from the stack
 * @line_number: line counter
 *
 * Return: no return
 */

void pop(int line_number)
{
	if (stack.top < 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack.top--;
}
