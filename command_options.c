#include "shell.h"

/**
 * command_options - handles commamd options based on command
 * @command: pointer to the command string
 * @argv: pointer to command line args strings
 * @runtime: pointer to runtime_t struct
 * Description: calls the required functions to perfom different options
 */


void command_options(char *command, const char **argv, runtime_t *runtime)
{
	int builtin = 0;

	builtin = builtin_command(command, argv, runtime);

	if (!builtin)
	{
		if (command[0] == '/' || (command[0] == '.' && command[1] == '/') || (command[0] == '.'  && command[1] == '.'))
		{
			if (_strchr(command, ' ') == NULL)
			{
				execute_command_no_args_with_path(command, argv, runtime);
			}
			else
			{
				execute_command_args_with_path(command, argv, runtime);
			}
		}
		else
			find_path(command, argv, runtime);

	}
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
