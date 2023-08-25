#include "monty.h"

/**
 * node_cnt - count the number of nodes in the stack
 *
 * Return: the total count
 */
int node_cnt(void)
{
	stack_t *runner = inf.head;
	int cnt = 0;

	while (runner)
	{
		cnt++;
		runner = runner->prev;
	}
	return (cnt);
}
