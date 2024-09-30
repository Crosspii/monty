#include "monty.h"

/**
 * push - pushes node to top of stack.
 * @stack: pointer to head node pointer of stack
 * @nline: line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fpritnf(stderr, "L%d: stack not found\n", nline);
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
 * pall - prints data of all nodes in the stack
 * @stack: pointer to head node pointer of stack.
 * @nline: line number.
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * nop - does NAIN.
 * @stack: pointer to head pointer of stack.
 * @nline: line number.
 * Return: NAIN
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}
