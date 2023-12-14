#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 1000
#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * stacks - stacks
 * @stack: stack size
 * @top: top of stack
 *
 * Description: node structure
 */
typedef struct stacks 
{
        int stack[STACK_SIZE];
        int top;
} Stack;

Stack stack;


/* Function Prototypes */
void free_stack(Stack *stack);
void add_node(stack_t **stack, int data);
void add_queue(stack_t **stack, int n);
/*void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);*/
void queue(stack_t **stack, unsigned int line_number);
/*void stack(stack_t **stack, unsigned int line_number);*/
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);


void push(int value, int line_number);
void pall(void);
void pint(int line_number);
void pop(int line_number);


#endif
