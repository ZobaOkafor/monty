#include "monty.h"


/**
 * free_stack - Free the memory used by the stack
 * @stack: Pointer to the head of the stack
 *
 * Return: Nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}


/**
 * _isalpha - This function checks for alphabetic character.
 * @c: The character to check, in ASCII code.
 *
 * Return: 1 if character is a letter, lowercase or uppercase,
 * else return 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	putchar('\n');
}


/**
 * isnumber - This function checks if a string is a number
 * @str: string being checked
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */

int isnumber(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);

	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}

