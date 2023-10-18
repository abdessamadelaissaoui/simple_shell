#include "shell.h"

/**
 * executecmd - executes  command
 * @tokens: argument of the command
 * Return: (void)
 **/
void executecmd(char **ntokens)
{
	char *pathEnv = getenv("PATH");
	char *pathToken;
	char *path;

	pathToken = strtok(pathEnv, ":");
	while (pathToken != NULL)
	{
		path = malloc(strlen(ntokens[0]) + strlen(pathToken) + 2);
		sprintf(path, "%s/%s", pathToken, ntokens[0]);
		execve(path, ntokens, NULL);

		pathToken = strtok(NULL, ":");
		free(path);
	}
}
