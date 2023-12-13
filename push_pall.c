#include "monty.h"

/**
 * push - This function adds a new node to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: No return value
 */

void push(stack_t **stack, unsigned int line_number)
{
	/*FILE *file = NULL;*/
	int value = 0;
	int n, i = 0, fg = 0;
	char /*content = NULL,*/ *arg = NULL;

	if (arg && arg[0] != '\0')
	{
		if (arg[0] == '-')
			i++;
		for (i = 0; arg[i] != '\0'; i++)
		{
			if(arg[i] > 57 || arg[i] < 48)
				fg = 1;
		}
		if (fg == 1)
		{
			dprintf(2, "L%d: Usage: push int\n", line_number);
			/*fclose(file);
			free(content);*/
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		dprintf(2, "L%d: Usage: push int\n", line_number);
		/*fclose(file);
		free(content);*/
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (value == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}


/**
 * pall - s function prints the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: no return
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

