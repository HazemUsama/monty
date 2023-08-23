#include "monty.h"

info inf = INIT_INF;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	inf.file = fopen(argv[1], "r");
	if (inf.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{

		inf.token = tokenize();
		call();
	}
	fclose(inf.file);
	return (0);
}
