#include "monty.h"

/**
 * push_to_stack -  pushes an integer to the stack.
 * @stack: pointer to the head point of the stack
 * @line_number: line number of content read
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	int num, i = 0, flag = 0;

	if (store.ag)
	{
		if (store.ag[0] == '-')
			i++;
		for (; store.ag[i] != '\0'; i++)
		{
			if (store.ag[i] < 48 || store.ag[i] > 57)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			close_free_and_fail(*stack, store.content, store.file);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		close_free_and_fail(*stack, store.content, store.file);
	}
	num = atoi(store.ag);
	if (store.flag == 0)
		add_node(stack, num);
	else
		add_queue(stack, num);
}

/**
 * add_node - Adds a node to the stack.
 * @head: Pointer to the head of the stack.
 * @n: value to add at the top.
 */
void add_node(stack_t **head, int n)
{
	stack_t *temp, *new;

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 */
void add_queue(stack_t **head, int n)
{
	stack_t *temp, *new;

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		temp->next = new;
		new->prev = temp;
	}
}

/**
 * print_all - prints the stack
 * @stack: stack head
 * @line_number: not used
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
