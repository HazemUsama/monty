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

	if (inf.cnt <= 2 || !is_int(inf.token[1]))
		print_err("usage: push integer");

	num = atoi(inf.token[1]);
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
