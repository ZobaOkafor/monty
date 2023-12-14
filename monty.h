#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>


extern int arg;


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


typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);


/**
 * myglo_var - global variables definition
 * @file: pointer to a FILE
 * @arg: integer to store push operations
 * @buff: pointer to char
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct myglo_var
{
	int arg;
	FILE *file;
	char *buff;
} glo_var;

extern glo_var gee_var;


/* Helper functions */
instruct_func get_ops(char *str);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);


/* Utility functions */
int _isalpha(int c);
int isnumber(char *str);
void free_stack(stack_t *stack);



/* function Prototypes */
void add_ops(stack_t **stack, unsigned int line_number);
void sub_ops(stack_t **stack, unsigned int line_number);
void mul_ops(stack_t **stack, unsigned int line_number);
void div_ops(stack_t **stack, unsigned int line_number);
void mod_ops(stack_t **stack, unsigned int line_number);
void nop_ops(stack_t **stack, unsigned int line_number);
void pop_ops(stack_t **stack, unsigned int line_number);
void pint_ops(stack_t **stack, unsigned int line_number);
void push_ops(stack_t **stack, unsigned int line_number);
void pall_ops(stack_t **stack, unsigned int line_number);
void swap_ops(stack_t **stack, unsigned int line_number);
void pstr_ops(stack_t **stack, unsigned int line_number);
void rotl_ops(stack_t **stack, unsigned int line_number);
void rotr_ops(stack_t **stack, unsigned int line_number);
void pchar_ops(stack_t **stack, unsigned int line_number);


#endif
