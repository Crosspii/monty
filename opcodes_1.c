#include "monty.h"

/**
  * push - pushes a node to the top of the stack.
  * @stack: pointer to the head node pointer of the stack.
  * @nline: line number of the command.
  *
  * Return: nothing.
  */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next = *stack;
	temp->prev = NULL;
	temp->n = arg.arg;
	if (*stack)
		(*stack)->prev = temp;
	*stack = temp;
}

/**
  * pall - prints the data of all nodes in the stack.
  * @stack: pointer to the head node pointer of the stack.
  * @nline: line number of the command.
  *
  * Return: nothing.
  */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
  * nop - does nothing.
  * @stack: pointer to the head node pointer of the stack.
  * @nline: line number of the command.
  *
  * Return: nothing.
  */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}
