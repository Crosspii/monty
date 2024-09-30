#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
  * struct arg_s - Represents an argument.
  * @arg: Integer value of the argument.
  * @flag: Option corresponding to a specific command.
  *
  * Description: Structure for argument parameters
  * passed to the Monty interpreter.
  */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

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
  * struct meta_s - Contains file and buffer data.
  * @buf: Pointer to the buffer containing data read from the file.
  * @stack: Pointer to the top of the stack.
  * @file: Pointer to the file being processed.
  */
typedef struct meta_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} meta_t;

/**
  * struct line_s - Represents the contents of a line and its number.
  * @tokens: Array of tokens parsed from the line.
  * @num: Line number in the source file.
  *
  * Description: Structure for holding data related to a line
  * in the input file.
  */
typedef struct line_s
{
	char **tokens;
	unsigned int num;
} line_t;

/* Function pointer type definition for opcode functions */
typedef void (*op_func_t)(stack_t **, unsigned int);

/* get_operations.c */
op_func_t get_op_func(line_t line, meta_t *meta);

/* parser_handler.c */
void parsefile(FILE *file);
void parseline(line_t *line, char *buffer);

/* check_handler.c */
bool is_comment(line_t line);
void check_push(line_t line, meta_t *meta, char *opcode);
bool check_argument(char *token);
int is_alpha(int c);

/* opcodes.c */
void push(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);

/* stack_handler.c */
void rot_left(stack_t **stack, unsigned int nline);
void rot_right(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);
void add_stack(stack_t **stack, unsigned int nline);

/* queue_handler.c */
void add_queue(stack_t **stack, unsigned int nline);
void to_queue(stack_t **stack, unsigned int nline);

/* prints.c */
void p_char(stack_t **stack, unsigned int nline);
void p_str(stack_t **stack, unsigned int nline);

/* operations.c */
void add_op(stack_t **stack, unsigned int nline);
void sub_op(stack_t **stack, unsigned int nline);
void mul_op(stack_t **stack, unsigned int nline);
void div_op(stack_t **stack, unsigned int nline);
void mod_op(stack_t **stack, unsigned int nline);

#endif
