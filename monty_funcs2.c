#include "monty.h"
/**
 * _pop - prints the top
 * @stack: stack head
 * @line_number: line_number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
