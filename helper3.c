#include "monty.h"

void freeToken()
{
	size_t i;

	if (inf.tokens == NULL)
		return;

	for (i = 0; inf.tokens[i]; i++)
	{
		free(inf.tokens[i]);
		inf.tokens[i] = NULL;
	}
	free(inf.tokens);
	
}

void freeStack()
{
	stack_t *curr;

	while (inf.head)
	{
		curr = inf.head->next;
		free(inf.head);
		inf.head = curr;
	}
}
