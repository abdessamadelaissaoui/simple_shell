#include "shell.h"

/**
 * main - take the cmd & execute it
 * Return: int
 **/
int main(void)
{
	int i;
	pid_t pid;
	char *command, **ntokens;
	size_t bufferSize = 1024;

	while (1)
	{
		write(1, "$ ", 2);
		command = malloc(1024 * sizeof(char));
		_getline(command, bufferSize);
		if (command)
		{
			if (strcmp(command, "exit") == 0)
			{
				_exitshell(command);
			}
			ntokens = tokenizer(command);
			pid = fork();
			if (pid == -1)
			{
			write(1, "hsh: Failed to fork the process\n", 31);
			}
			else if (pid == 0)
			{
				if (strcmp(ntokens[0], "env") == 0)
					printenv();
				else
					executecmd(ntokens);
				exit(0);
			}
			else
				wait(NULL);

			for (i = 0; ntokens[i] != NULL; i++)
				free(ntokens[i]);
			free(ntokens);
		}
		free(command);
	}
	return (0);
}
