#include "monty.h"
#include <stdio.h>


/**
 * push - push an element onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * @value: value to push onto the stack
 */

void push(stack_t **stack, unsigned int line_number)
{
        int value = 0;
	stack_t *new_node;

        (void)line_number;

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
 * main - Monty ByteCode Interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
        FILE *file = NULL;
	int found = 0;
        char *arg, *opcode;
        char *line = NULL;
        size_t i, len = 0;
        stack_t *stack = NULL;
        unsigned int line_number = 0;

        instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
        };

	/*(void)argv;*/

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
		 return (EXIT_FAILURE);
        }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

        while (getline(&line, &len, file) != -1)
        {
                line_number++;
                opcode = strtok(line, " \t\n");
                if (opcode == NULL || opcode[0] == '#')
                        continue;


                if (strcmp(opcode, "push") == 0)
                {
                        arg = strtok(NULL, " \t\n");
                        if (arg == NULL)
                        {
                                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                free_stack(stack);
                                free(line);
                                fclose(file);
                                return (EXIT_FAILURE);
                        }
			/*value = 0;
                        value = atoi(arg);
                        push(&stack, line_number, value);*/
                }

                for (i = 0; instructions[i].opcode != NULL; i++)
                {
                        if (strcmp(opcode, instructions[i].opcode) == 0)
 			{
                                instructions[i].f(&stack, line_number);
                                found = 1;
                                break;
                        }
                }

                if (!found)
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                        free_stack(stack);
                        free(line);
                        fclose(file);
                        return (EXIT_FAILURE);
                }
        }

        free_stack(stack);
        free(line);
        fclose(file);

        return (EXIT_SUCCESS);
}
