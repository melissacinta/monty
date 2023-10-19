#include "monty.h"

/**
 * swap -  swaps integer data from top to previous
 * @stack: provided stack to swap
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int num = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		 close_free_and_fail(*stack, store.content, store.file);
	}
	tmp = *stack;
	num = tmp->n;

	tmp->n = tmp->next->n;
	tmp->next->n = num;
}
