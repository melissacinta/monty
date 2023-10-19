#include "monty.h"

/**
 * _add -  adds the first two nodes of a given stack
 * @stack: stack from main
 * @line_number: line counter
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		 close_free_and_fail(*stack, store.content, store.file);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_number); /*For top node*/
	(*stack)->n = result;
}
