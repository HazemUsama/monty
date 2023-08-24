#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
	char *token, *str_copy = strdup(str);
	
	if (str_copy == NULL)
	{
		if (str)
			free(str);
		malloc_failed();
	}

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
	int argCount = 0, i;

	line = readInput();
	if (line == NULL)
		return (NULL);
	inf.cnt = countTokens(line, " \n");

	if (inf.cnt == 1)
	{
		free(line);
		return (NULL);
	}

	arg = malloc(sizeof(char *) * inf.cnt);
	if (arg == NULL)
	{
		free(line);
		malloc_failed();
	}

	token = strtok(line, " \n");
	while (token)
	{
		arg[argCount] = strdup(token);
		if (arg[argCount] == NULL)
		{
			free(line);
			for (i = 0; i < argCount; i++)
				free(arg[i]);

			malloc_failed();
		}
		argCount++;
		token = strtok(NULL, " \n");
	}
	arg[argCount] = NULL;
	free(line);
	inf.cnt--;
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

	if (getline(&line, &len, inf.file) == EOF)
	{
		free(line);
		freeAll();
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
	freeAll();
	exit(EXIT_FAILURE);
}
/**
 * malloc_failed - exit with an error message when allocation falis
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	freeAll();
	exit(EXIT_FAILURE);
}

