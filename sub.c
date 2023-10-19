#include "monty.h"

/**
 * _sub -  substracts the first two nodes in the stack
 * @stack: stack given by main
 * @line_number: line counter
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_number);/*For top node*/
	(*stack)->n = result;
}
