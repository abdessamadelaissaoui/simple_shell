#include "shell.h"

/**
 * tokenizer - tokenizer command
 * @command: the command to tokenize
 * Return: pointer to pointer
 **/
char **tokenizer(char *command)
{
	int i = 0;
	char *token;
	char **ntokens;

	ntokens = malloc(20 * sizeof(char *));

	token = strtok(command, " ");
	while (token != NULL)
	{
		ntokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	ntokens[i] = NULL;

	return (ntokens);
}
