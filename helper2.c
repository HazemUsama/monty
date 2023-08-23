#include "monty.h"
#include <stdio.h>

/**
 * call - compare the opcode and call the right function
 */
void call(void)
{
	int i;
	instruction_t instruct[] = {
	{"push", _push},
	{"pall", _pall},
		{NULL, NULL}
	};
	i = 0;
	while (instruct[i].opcode)
	{
		if (strcmp(instruct[i].opcode, inf.token[0]) == 0)
		{
			instruct[i].f(&inf.head, inf.line_number);
			return;
		}
		i++;
	}
	print_err("unknown instruction");
}

/**
 * is_int - check if it's integer or not
 *
 * @str: the integer
 *
 * Return: 1 if it's 0 if not
 */
int is_int(char *str)
{
	if (*str && *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/**
 * create_node - creat a new node
 *
 * @n: the value the node have
 *
 * Return: the node;
 */
stack_t *create_node(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		malloc_faild();
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 *
 * @str: the source string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *copy;
	int i, size = 0;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;

	copy = (char *)malloc((sizeof(char) * size) + 1);
	if (copy == NULL)
	return (NULL);

	for (i = 0; i < size; i++)
		copy[i] = str[i];
	copy[size] = '\0';

	return (copy);
}

/**
 * _getline - custom getline function
 *
 * @lineptr: ...
 * @n: ...
 * @stream: ...
 *
 * Return: ...
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t pos = 0;
	char *temp;

	if (lineptr == NULL || n == NULL)
		return (-1);


	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos >= *n - 1)
		{
			*n *= 2;
			temp = (char *)realloc(*lineptr, *n);
			if (temp == NULL)
				return (-1);
			*lineptr = temp;
		}

		(*lineptr)[pos++] = (char)c;

		if (c == '\n')
			break;
	}

	if (pos == 0 && c == EOF)
		return (-1);

	(*lineptr)[pos] = '\0';
	return ((ssize_t) pos);
}
