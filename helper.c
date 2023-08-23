#include "monty.h"

/**
 * countTokens - count the number of tokens in a string
 *
 * @str: the string to count tokens in
 * @delim: the delimiter used to split the string into tokens
 *
 * Return: the number of tokens in the string
 */
int countTokens(char *str, const char *delim)
{
	int count = 0;
	char *token, *str_copy = _strdup(str);

	token = strtok(str_copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;
	free(str_copy);
	return (count);
}

/**
 * tokenize - split the line to multple strings
 *
 * Return: a pointer to the strings on success and NULL on failure
 */
char **tokenize(void)
{
	char *line, *token;
	char **arg = NULL;
	int argCount = 0;

	line = readInput();
	inf.cnt = countTokens(line, " \n") - 1;
	if (inf.cnt == 1)
		return (NULL);

	arg = malloc(sizeof(char *) * inf.cnt);
	if (arg == NULL)
	{
		malloc_faild();
	}
	token = strtok(line, " \n");
	while (token)
	{
		arg[argCount] = _strdup(token);
		if (arg[argCount++] == NULL)
		{
			malloc_faild();
		}
		token = strtok(NULL, " \n");
	}
	arg[argCount] = NULL;
	free(line);
	return (arg);
}

/**
 * readInput - read input from the terminal
 *
 * Return: the input
 */
char *readInput(void)
{
	size_t len = 0;
	char *line = NULL;

	if (_getline(&line, &len, inf.file) == EOF)
	{
		freeStack();
		exit(EXIT_SUCCESS);
	}

	return (line);
}
/**
 * print_err - print a message to stderr and exit
 *
 * @message: the message to print
 */
void print_err(char *message)
{
	fprintf(stderr, "L%d: %s\n", inf.line_number, message);
	freeToken();
	freeStack();
	exit(EXIT_FAILURE);
}
/**
 * malloc_faild - exit with an error message when allocation falis
 */
void malloc_faild(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	freeToken();
	freeStack();
	exit(EXIT_FAILURE);
}

