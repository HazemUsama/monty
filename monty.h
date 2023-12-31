#ifndef MONTY_H
#define MONTY_H

#define INIT_INF { 0, 1, 0, NULL, NULL, NULL, NULL }
#define notUsed __attribute__((unused))
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - struct to save info about the stack
 *
 * @line_number: the line number
 * @flag: if it's stack (1) else (0)
 * @cnt: number of arguments
 * @tokens: the line arguments
 * @file: the file we read from
 * @head: the head of the linked list
 * @tail: the tail of the linked list
 *
 */
typedef struct info_s
{
	int line_number;
	int flag;
	int cnt;
	char **tokens;
	FILE *file;
	stack_t *head;
	stack_t *tail;

} info;



/* Functions */
int countTokens(char *str, const char *delim);
char *readInput(void);
char **tokenize(void);
void malloc_failed(void);
void print_err(char *message);
int is_int(char *str);
stack_t *create_node(int n);
void call(void);
void freeToken(void);
void freeStack(void);
void freeAll(void);
void swap_n(int *a, int *b);
int node_cnt(void);

/* Monty Functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);



extern info inf;
#endif
