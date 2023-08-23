#include "monty.h"
void parase(info *info);
void checktoken(info *info);
void read(info *info)
{	
	int r;
	size_t n;
	r = 0, n = 0;
	r = getline(info->line, size_t &n, info->file);
	while (r != -1)
	{
		(info->count)++;
		parase(info);
		//increase counter
		//update info struct
		//parase line 
		//checking for parase function and passing the opcode to operation function s with hazem
		//read the next line 
	
	
	}

	void parase(info *info)
	{
		char *opcode;
		info->token = strtok(info->line, "\t\s\n");
		if ((info->token) != NULL)
		{
			while(info->line)
			{
				opcode = checktoken(info); // checking if that token is an opcode
				if (!opcode)
				{
					
				}
				stackopcode(opcode); // if yes an opcode then code it
				info->token = strtok(info->line,NULL);
			}
		}
		exit();
	
	}

	char* checktoken(info *info)
	{
		if (info->token[0] == $)
	
	
	
	}



}
