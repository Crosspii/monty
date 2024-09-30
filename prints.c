#include "monty.h"

/**
  * p_char - prints char at top of stack
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  * Return: NAIN
  */
void p_char(stack_t **stack, unsigned int nline)
{
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}
	c = temp->n;
	if (is_alpha(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}


/**
  * p_str - prints a string from ascii starting from the top.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  * Return: NAIN
  */
void p_str(stack_t **stack, unsigned int nline)
{
	stack_t *h;
	(void)nline;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
