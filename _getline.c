#include "shell.h"

/**
 * _getline : take input form STDIN
 * @buffer: stores the input
 * @bufferSize: size of buffer
 **/
void _getline(char *buffer, size_t bufferSize)
{
	ssize_t bytes;

	bytes = getline(&buffer, &bufferSize, stdin);
	if (bytes == -1)
		perror("hsh");
	else
		buffer[strcspn(buffer, "\n")] = '\0';
}
