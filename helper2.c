#include "monty.h"
#include <stdlib.h>

/**
 * call - compare the opcode and call the right function
 */
void call(void)
{
	int i;
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	i = 0;
	while (instruct[i].opcode)
	{
		if (strcmp(instruct[i].opcode, inf.tokens[0]) == 0)
		{
			instruct[i].f(&inf.head, inf.line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
	 inf.line_number, inf.tokens[0]);
	freeAll();
	exit(EXIT_FAILURE);
}

/**
 * is_int - check if it's integer or not
 *
 * @str: the integer
 *
 * Return: 1 if it's 0 if not
 */
int is_int(char *str)
{
	size_t i;

	if (str == NULL)
		return (0);

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * create_node - creat a new node
 *
 * @n: the value the node have
 *
 * Return: the node;
 */
stack_t *create_node(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		malloc_failed();
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}


