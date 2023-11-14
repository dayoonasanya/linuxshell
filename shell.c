#include "shell.h"


void free_resources(char *command, runtime_t *runtime)
{
	if (command)
		free(command);

	if (runtime->error_msg)
		free(runtime->error_msg);

	free(runtime);

}

/**
 * signal_interaption - checks for SIGINT signal
 * @signo: signal number
 */

void signal_interaption(int signo)
{
	if (signo == SIGINT)
	{
		setenv("Ctrl_C", "set", 1);
	}
}

/**
 * start_shell - starts the shell
 * @argv: pointer to command line args strings
 * @runtime: pointer to  the struct for shell exec info
 * Description: prints the prompt.
 * Gets the user input from keyboard
 * Starts the required functions
 * loops
 */


void start_shell(const char **argv, runtime_t *runtime)
{
	char *command = NULL;
	size_t n = 0;

	signal(SIGINT, signal_interaption);

	while (1)
	{
		if (_strcmp("set", _getenv("Ctrl_C")) == 0)
		{
			setenv("Ctrl_C", "not_set", 1);
			if (command)
			{
				free(command);
				command = NULL;
			}

			continue;
		}


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
			continue;

		command_options(command, argv, runtime);

		if (command)
		{
			free(command);
			command = NULL;
		}
	}

	free_resources(command, runtime);

}
