#include "monty.h"

/**
 * pstr - prints the string value of a stack
 * @stack: the stack
 * @line_number: line counter for error messages
 */

void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n); /*converts the integer to characters*/
		current = current->next;
	}
	putchar('\n');
}
