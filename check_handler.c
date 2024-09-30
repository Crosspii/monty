#include "monty.h"

arg_t arg = {0, 0};

/**
  * is_comment - Checks if the line is a comment.
  * @line: Struct containing the line content and number.
  *
  * Return: true if the line is a comment, otherwise false.
  */
bool is_comment(line_t line)
{
	if (!line.tokens[0])
	{
		free(line.tokens);
		return (true);
	}

	if (line.tokens[0][0] == '#')
	{
		free(line.tokens);
		return (true);
	}

	return (false);
}

/**
  * check_argument - Validates the argument.
  * @token: Argument to be checked.
  *
  * Return: true if valid, otherwise false.
  */
bool check_argument(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}


/**
  * check_push - Checks if the push opcode is being used and sets
  * the global argument variable if true.
  * @line: Struct containing the line content and number.
  * @opcode: Opcode to compare.
  * @meta: Struct containing all allocated memory.
  *
  * Return: None.
  */
void check_push(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) &&  !check_argument(line.tokens[1]))
	{
		free(line.tokens);
		fprintf(stderr, "L%d: usage: push integer\n", line.num);
		free(meta->buf);
		free_stack(&(meta->stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.tokens[1]);
}

/**
  * is_alpha - Checks if the character is an alphabet.
  * @c: Character to check.
  *
  * Return: 1 if it is an alphabet, 0 otherwise.
  */
int is_alpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}
