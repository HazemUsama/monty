#include "monty.h"


/**
 * freeToken - free the tokens
 */
void freeToken(void)
{
	size_t i;

	if (inf.tokens == NULL)
		return;
	for (i = 0; inf.tokens[i]; i++)
		free(inf.tokens[i]);
	free(inf.tokens);
	inf.tokens = NULL;
}
/**
* freeStack - free the stack
*/
void freeStack(void)
{
	stack_t *curr;

	while (inf.head)
	{
		curr = inf.head->prev;
		free(inf.head);
		inf.head = curr;
	}
}

/**
 * is_empty - checking if the stack is empty
 *
 * Return: boolean
 */

bool is_empty(void)
{
	return (inf.head == NULL);
}


