#include "monty.h"

/**
 * _push - push a node to the stack
 *
 * @stack: the head of the stack
 * @line_number: ...
 */
void _push(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	stack_t *new_node;
	int num;

	if (inf.cnt < 2 || !is_int(inf.tokens[1]))
		print_err("usage: push integer");

	num = atoi(inf.tokens[1]);
	new_node = create_node(num);
	if (inf.head == NULL)
	{
		inf.head = new_node;
		inf.tail = new_node;
	}
	else
	{
		new_node->prev = inf.head;
		inf.head->next = new_node;
		inf.head = new_node;
	}
}
/**
 * _pall - print the whole stack
 *
 * @stack: the head of the stack
 * @line_number: ...
 */
void _pall(stack_t **stack, unsigned int notUsed line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%i\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * is_empty - checking if the stack is empty
 * @stack: stack
 * Return: bolean
 */

bool is_empty()
{
	return ((inf.head) == NULL);
}

/**
 * _pall - print the top 
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */

void _pint(stack_t notUsed **stack, unsigned int notUsed line_number)
{
	if (is_empty())
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", inf.line_number);
		exit(EXIT_FAILURE);
	}
	if (strcmp((inf.tokens[0]), "pint") != 0)
		print_err("usage: pint");
	printf("%d\n", inf.head->n);

}
