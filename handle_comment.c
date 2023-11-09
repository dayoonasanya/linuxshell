#include "shell.h"


/**
 * handle_comment - remove comment.
 * @input: input.
 *
 * Return: return nothing.
 */

void handle_comment(char *input)
{
	int j = 0;

	if (input[j] == '#')
		input[j] = '\0';
	while (input[j] != '\0')
	{
		if (input[j] == '#' && input[j - 1] == ' ')
			break;
		j++;
	}
	input[j] = '\0';
}
