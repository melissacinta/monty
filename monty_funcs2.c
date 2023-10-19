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

/**
 * _div -  divides the second top element of the stack by the top element
 * of the stack
 * @stack: stack from main
 * @line_number: line counter
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_number); /*For top node*/
	(*stack)->n = result;
}

/**
 * _mod -  computes remainder of the second top element of the stack divded by
 * the top element of the stack
 * @stack: stack from main
 * @line_number: line counter
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_number); /*For top node*/
	(*stack)->n = result;
}

/**
 * _pchar -  computes remainder of the second top element of the stack
 * divided by the top element of the stack
 * @stack: stack from main
 * @line_number: line counter
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * _rotl - rotates the stack to the top
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Pointer to a pointer pointing to top node of the stack.
 */

void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
