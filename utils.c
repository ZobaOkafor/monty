#include "monty.h"


/**
 * initialize_stack - This function intializes the stack variable
 *
 */

void initialize_stack(void)
{
	stack.top = -1;
	memset(stack.stack, 0, sizeof(stack.stack));
}
