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
	stack_t *runner;

	while (inf.head)
	{
		runner = inf.head->prev;
		free(inf.head);
		inf.head = runner;
	}
}


/**
 * freeAll - free all allocated meomry
 */
void freeAll(void)
{
	freeToken();
	freeStack();
	fclose(inf.file);
}

/**
 * swap_n - swap two numbers
 *
 * @a: first number
 * @b: second number
 */
void swap_n(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
