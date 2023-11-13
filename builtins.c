#include "shell.h"

/**
 * exit_shell - exits the shell
 * @command: command string
 * @argv: command line arguments
 * @runtime: pointer to runtime_t struct
 * Description: exits with status 0 or
 * given status or
 * prints error if status is invalid
 */
void exit_shell(char *command, const char **argv, runtime_t *runtime)
{
	int status = 0;

	if (_strchr(command, ' ') == NULL)
	{
		free(command);

		if (runtime->error_msg)
			free(runtime->error_msg);
		free(runtime);
		exit(0);
	}
	else
	{
		command = _strrev(command);
		trim_start(&command);
		command = _strrev(command);
		status = _atoi(command + 4);

		if (contains_chars(command + 4))
		{
			char error[256];

			snprintf(error, sizeof(error), "%s: %d: exit: Illegal number:  %s", *argv,
					runtime->error_number, command + 4);
			runtime->error_number++;
			puts(error);
		}
		else
		{
			free(command);

			if (runtime->error_msg)
				free(runtime->error_msg);

			free(runtime);
			exit(status);
		}
	}
}

/**
 * print_env - prints environment variable of the running programme
 * Return: void
 */
void print_env(void)
{
	int i;

	while (environ[i])
	{
		puts(environ[i]);

		i++;
	}
}

/**
 * builtin_command - selects the built in commands to run
 * @command: command
 * @argv: command line arguments
 * @runtime: pointer to a struct containing shell info
 * Return: 1 if one built command matches with the typed command
 * or 0 if not
 */
int builtin_command(char *command, const char **argv, runtime_t *runtime)
{
	int status = 0;

	if (_strncmp(command, "exit", 4) == 0)
	{
		status = 1;
		exit_shell(command, argv, runtime);
	}
	else if (_strcmp(command, "env") == 0)
	{
		print_env();
		status = 1;
	}


	if (runtime)
	{

	}

	return (status);
}
