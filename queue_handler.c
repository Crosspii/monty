#include "monty.h"

/**
  * add_queue - Sets the mode to push to the queue
  * @stack: Double pointer to the stack.
  * @nline: Line number of the command.
  *
  * Return: None
  */
void add_queue(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}

/**
  * to_queue - Adds a new element to the queue instead of the stack
  * @stack: Double pointer to the head node of the stack
  * @nline: Line number of the command
  *
  * Return: None
  */
void to_queue(stack_t **stack, unsigned int nline)
{
	stack_t *new, *last;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last  = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
