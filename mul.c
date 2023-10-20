#include "monty.h"

/**
 * _mul - multiiplies the next top value by the top value
 * @stack: passed from  main
 * @line_number: line counter
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_number);/*removes the top node */
	(*stack)->n = result;
}
