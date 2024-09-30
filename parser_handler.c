#include "monty.h"

/**
 * parseline - parses then tokenizes a line of test storing it
 * int a line struct
 * @line: a struct containing content and line number
 * @buffer: string of text read from a script file
 * Return: nothing.
 */
void parseline(line_t *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file line by line.
 * @file: script to be read
 * Return: nothing.
 */
void parsefile(FILE *file)
{
	size_t size = 0;
	meta_t *meta = NULL;
	line_t line;

	meta = malloc(sizeof(meta_t));
	if (!meta)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;

	meta->file = file;
	meta->stack = NULL;
	meta->buf = NULL;

	while (getline(&(meta->buf), &size, meta->file) != -1)
	{
		line.number++;
		parseline(&line, meta->buf);
		if (line.content)
			get_op_func(line, meta)(&(meta->stack), line.number);
	}

	free(meta->buf);
	free_stack(&(meta->stack));
	fclose(meta->file);
	free(meta);
}
