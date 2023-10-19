#include "monty.h"

/**
 * call_func - calls corresponding sunction based on the opcode
 * @stack: head odf the doubly linked list
 * @counter: line counter
 * @file: poiner to file containing monty bytecode
 * @content: line content
 * Return: 0 on success and 1 on failure
 */
int call_func(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t funcs[] = {
		{"push", push_to_stack}, {"pall", print_all}, {"pint", _pint},
		{"pop", _pop}, {"swap", swap}, {"add", _add}, {"nop", nop},
		{"div", _div}, {"mod", _mod}, {"pchar", _pchar}, {"rotl", _rotl},
		{"stack", _stack}, {"queue", _queue}, {"pstr", pstr}, {"sub", _sub},
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
		close_free_and_fail(*stack, content, file);
	}
	return (1);
}

/**
 * close_free_and_fail - function to close, free and exit a process
 * @stack: head of the stack
 * @content: content to be freed
 * @file: file to be closed
 */
void close_free_and_fail(stack_t *stack, char *content, FILE *file)
{
	fclose(file);
	free(content);
	free_stack(stack);
	exit(EXIT_FAILURE);
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
