#include "monty.h"

/**
 * _stack - change flag to 0
 * @stack: stack from main
 * @line_number: line counter
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	store.flag = 0;
}

/**
 * _queue - change flag to 1
 * @stack: stack from main
 * @line_number: line counter
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	store.flag = 1;
}
