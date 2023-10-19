#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct store_s - variables -ag, file, line content
 * @ag: value
 * @file: pointer to monty file
 * @content: line content
 * @flag: flag change stack <-> queue
 * Description: stores values through the program
 */
typedef struct store_s
{
	char *ag;
	FILE *file;
	char *content;
	int flag;
}  store_t;
extern store_t store;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *head);
int call_func(char *content, stack_t **head, unsigned int counter, FILE *file);
void close_free_and_fail(stack_t *stack, char *content, FILE *file);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);

#endif
