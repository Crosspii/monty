#include "monty.h"

/**
  * get_op_func - searches and matches text to opcode
  * and returns the corresponding function pointer.
  * @line: struct containing line content and line number.
  * @meta: struct containing all allocated memory resources.
  *
  * Return: pointer to the relevant function for the opcode.
  */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add_op},
		{"sub", sub_op},
		{"mul", mul_op},
		{"div", div_op},
		{"mod", mod_op},
		{"nop", nop},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rot_left},
		{"rotr", rot_right},
		{"stack", add_stack},
		{"queue", add_queue},
		{NULL, NULL}
	};

	if (is_comment(line))
		return (nop);

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.tokens[0]) == 0)
		{
			check_push(line, meta, ops[i].opcode);
			if (arg.flag == 1 && strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.tokens)
					free(line.tokens);
				return (to_queue);
			}
			free(line.tokens);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n",
			line.num, line.tokens[0]);
	free(line.tokens);
	free(meta->buf);
	free_stack(&(meta->stack));
	fclose(meta->file);
	free(meta);
	exit(EXIT_FAILURE);
}
