#include "monty.h"

/**
  * add_op - Adds the top two elements of the stack.
  * @stack: Pointer to the head node pointer of the stack.
  * @nline: Line number in the script.
  *
  * Return: None
  */
void add_op(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * sub_op - Subtracts the top element from the second top element
  *          of the stack.
  * @stack: Pointer to the head node pointer of the stack.
  * @nline: Line number in the script.
  *
  * Return: None
  */
void sub_op(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * div_op - Divides the second top element by the top element of the stack.
  * @stack: Pointer to the head node pointer of the stack.
  * @nline: Line number in the script.
  *
  * Return: None
  */
void div_op(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * mul_op - Multiplies the top two elements of the stack.
  * @stack: Pointer to the head node pointer of the stack.
  * @nline: Line number in the script.
  *
  * Return: None
  */
void mul_op(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * mod_op - Computes the modulus of the second top element
  *          by the top element of the stack.
  * @stack: Pointer to the head node pointer of the stack.
  * @nline: Line number in the script.
  *
  * Return: None
  */
void mod_op(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
