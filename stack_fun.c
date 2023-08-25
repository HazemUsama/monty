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
		if (inf.flag)
		{
			new_node->prev = inf.head;
			inf.head->next = new_node;
			inf.head = new_node;
		}
		else
		{
			new_node->next = inf.tail;
			inf.tail->prev = new_node;
			inf.tail = new_node;
		}
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
	stack_t *runner = *stack;

	while (runner)
	{
		printf("%i\n", runner->n);
		runner = runner->prev;
	}
}

/**
 * _pint - print the top
 * @stack: stack
 * @line_number: line number
 */
void _pint(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (!node_cnt())
		print_err("can't pint, stack empty");

	printf("%d\n", inf.head->n);

}
/**
 * _pop - pop the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void _pop(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	stack_t *new_head;

	if (!node_cnt())
		print_err("can't pop an empty stack");
	new_head = inf.head->prev;
	free(inf.head);
	inf.head = new_head;
}

/**
 * _swap - swap the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _swap(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't swap, stack too short");
	swap_n(&inf.head->n, &inf.head->prev->n);
}
