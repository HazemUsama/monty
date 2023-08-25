#include "monty.h"



/**
 * _mod - rest of division of the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _mod(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't mod, stack too short");
	if (!inf.head->n)
		print_err("division by zero");
	inf.head->prev->n %= inf.head->n;
	_pop(&inf.head, inf.line_number);
}

/**
 * _pchar - print the top of the stack as char
 * @stack: stack
 * @line_number: line number
 */
void _pchar(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (!node_cnt())
		print_err("can't pchar, stack empty");
	if (inf.head->n < 32 || inf.head->n > 126)
		print_err("can't pchar, value out of range");
	printf("%c\n", inf.head->n);
}


/**
 * _pstr - print a string starting from the top
 * @stack: stack
 * @line_number: line number
 */
void _pstr(stack_t **stack, notUsed unsigned int line_number)
{
	stack_t *runner = *stack;

	while (runner)
	{
		if (runner->n < 32 || runner->n > 126)
			break;

		printf("%c", runner->n);
		runner = runner->prev;

	}
	printf("\n");
}
/**
 * _rotl - rotates the stack to the left
 * @stack: stack
 * @line_number: line number
 */
void _rotl(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	stack_t *sec_top;

	if (node_cnt() < 2)
		return;
	sec_top = inf.head->prev;
	sec_top->next = NULL;
	inf.head->prev = NULL;
	inf.head->next = inf.tail;
	inf.tail->prev = inf.head;
	inf.tail = inf.head;
	inf.head = sec_top;
}

/**
 * _rotr - rotates the stack to the right
 * @stack: stack
 * @line_number: line number
 */
void _rotr(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	stack_t *sec_back;

	if (node_cnt() < 2)
		return;
	sec_back = inf.tail->next;
	sec_back->prev = NULL;
	inf.tail->next = NULL;
	inf.tail->prev = inf.head;
	inf.head->next = inf.tail;
	inf.head = inf.tail;
	inf.tail = sec_back;
}
