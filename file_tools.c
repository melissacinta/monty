#include "monty.h"

/**
  i * call_func - calls corresponding sunction based on the opcode
 * @stack: head odf the doubly linked list
 * @counter: line counter
 * @file: poiner to file containing monty bytecode
 * @content: line content
 * Return: 0 on success and 1 on failure
 */
int call_func(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t funcs[] = {
		{"push", push_to_stack}, {"pall", print_all}, {"pint", print_int},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	store.ag = strtok(NULL, " \n\t");
	while (funcs[i].opcode && op)
	{
		if (strcmp(op, funcs[i].opcode) == 0)
		{
			funcs[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && funcs[i].opcode == NULL)
	{ 
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *h;

	h = head;
	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
