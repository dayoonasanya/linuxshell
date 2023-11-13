#include "shell.h"

void handle_comment(char *input);
void handle_newline(char *str);

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


/**
 *handle_newline - remove newline.
 *@str: string source.
 *
 *Return: return nothing.
 */
void handle_newline(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			break;
		j++;
	}
	str[j] = '\0';
}
