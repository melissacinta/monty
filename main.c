#include "monty.h"
store_t store = {NULL, NULL, NULL, 0};

/**
 * main - function tp read monty byte code
 * @ac: arguement count
 * @av: arguement vector
 * Return: an integer value 0
 */

int main(int ac, char *av[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t input_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	store.file = file;
	while (input_line > 0)
	{
		content = NULL;
		input_line = getline(&content, &size, file);
		store.content = content;
		counter++;
		if (input_line > 0)
		{
			call_func(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
