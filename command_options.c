#include "shell.h"

/**
 * command_options - handles commamd options based on command
 * @command: pointer to the command string
 * @argv: pointer to command line args strings
 * Description: calls the required functions to perfom different options
 */


void command_options(char *command, const char **argv)
{
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
	{
		if (_strchr(command, ' ') == NULL)
		{
			execute_command_no_args_with_path(command, argv);
		}
		else
		{
			execute_command_args_with_path(command, argv);
		}
	}
	else
		find_path(command, argv);
}

/**
 * print_prompt - prints a prompt to stdout.
 * Return: void
 * Description: prints the prompt only if
 * input is comming from the keyboard in the terminal
 */

void print_prompt(void)
{
	char *prompt = "$) ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, _strlen(prompt));
}
