#include "shell.h"

/**
 * _exitshell - exit with error num
 * @command: command > free
 * Return: (void)
 **/
void _exitshell(char *command)
{
	free(command);
	exit(0);
}
