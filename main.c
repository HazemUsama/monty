#include "monty.h"
int main(int argc, char **argv)
{	
	if(argc != 2)
	{
		fprintf(strerr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info->file = fopen(argv[1], "r");
	if (info->file == NULL)
	{
		fprintf(strerr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	read(info->file);
	fclose(info->file);
	return (0);
}
