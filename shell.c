#include "shell.h"

/**
 * signal_interaption - checks for SIGINT signal
 * @signo: signal number
 * Description: if signal is SIGINT it exits with
 * status 127
 */

void signal_interaption(int signo)
{
	if (signo == SIGINT)
	{
		_putchar('\n');
		exit(127);
	}
}

/**
 * start_shell - starts the shell
 * @argv: pointer to command line args strings
 * Description: prints the prompt.
 * Gets the user input from keyboard
 * Starts the required functions
 * loops
 */


void start_shell(const char **argv)
{
	char *command = NULL;
	size_t n = 0;

	signal(SIGINT, signal_interaption);

	while (1)
	{
		print_prompt();

		if (getline(&command, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}

		command[_strcspn(command, "\n")] = '\0';

		trim_start(&command);

		if (*command == '\0')
		{
			continue;
		}

		command_options(command, argv);
		free(command);
		command = NULL;
	}


	if (command)
		free(command);

}
