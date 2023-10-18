#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char **tokenizer(char *command);
void executecmd(char **tokens);
void _getline(char *buffer, size_t bufferSize);
void printenv(void);
void _exitshell(char *command);

#endif
