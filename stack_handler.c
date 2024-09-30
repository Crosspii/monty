#include "monty.h"

/**
  * add_stack - changes mode of push to stack.
  * @stack: pointer to stack.
  * @nline: line number.
  *
  * Return: NAIN!!
  */
void add_stack(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
  * free_stack - frees all nodes in a stack.
  * @stack: pointer to head node pointer of a stack.
  *
  * Return: NAIN
  */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
  * rot_left - rotates stack to the left
  * @stack: pointer to the head node pointer of stack
  *
  * @nline: line number
  * Return: NAIN
  */
void rot_left(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}

/**
  * rot_right - rotates stack to the right.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void rot_right(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}
