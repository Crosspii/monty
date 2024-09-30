#include "monty.h"

/**
  * add_stack - changes mode of push to stack.
  * @stack: pointer to the stack.
  * @nline: line number.
  *
  * Return: void
  */
void add_stack(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
  * free_stack - frees all nodes in a stack.
  * @stack: pointer to the head node pointer of the stack.
  *
  * Return: void
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
  * rot_left - rotates the stack to the left.
  * @head: pointer to the head node pointer of the stack.
  * @counter: line number.
  *
  * Return: void
  */
void rot_left(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
  * rot_right - rotates the stack to the right.
  * @head: pointer to the head node pointer of the stack.
  * @counter: line number.
  *
  * Return: void
  */
void rot_right(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
