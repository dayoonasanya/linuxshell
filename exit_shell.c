#include "shell.h"


/**
* exit_shell - exit shell.
* @command: command.
* @line: shell.
*
* Return: Nothing.
*/


void exit_shell(char **command, char *line)
{
	free(line);
	free_buf(command);
	exit(0);
}



/**
* free_buf - command to free buf.
* @buffer: buf.
*
* Return: nothing.
*/
void free_buf(char **buffer)
{
	int j = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[j])
	{
		free(buffer[j]);
		j++;
	}
	free(buffer);
}
