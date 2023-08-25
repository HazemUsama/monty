#include "monty.h"

/**
 * _add - add the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _add(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't add, stack too short");
	inf.head->prev->n += inf.head->n;
	_pop(&inf.head, inf.line_number);
}

/**
 * _nop - do nothing
 * @stack: stack
 * @line_number: line number
 */
void _nop(notUsed stack_t **stack, notUsed unsigned int line_number)
{
}


/**
 * _sub - subtracts the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _sub(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't sub, stack too short");
	inf.head->prev->n -= inf.head->n;
	_pop(&inf.head, inf.line_number);
}


/**
 * _div - divides the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _div(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't div, stack too short");
	if (!inf.head->n)
		print_err("division by zero");
	inf.head->prev->n /= inf.head->n;
	_pop(&inf.head, inf.line_number);
}

/**
 * _mul - multiplies the last two nodes
 * @stack: stack
 * @line_number: line number
 */
void _mul(notUsed stack_t **stack, notUsed unsigned int line_number)
{
	if (node_cnt() < 2)
		print_err("can't mul, stack too short");
	inf.head->prev->n *= inf.head->n;
	_pop(&inf.head, inf.line_number);
}
