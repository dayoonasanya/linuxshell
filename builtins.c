#include "shell.h"


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
			snprintf(error, sizeof(error), "%s: %d: exit: Illegal number:  %s", *argv, runtime->error_number, command + 4);
			runtime->error_number++;
			puts(error);
		 }
		 else
		 {
			free(command);
	
			if (runtime->error_msg)
				free(runtime->error_msg);
			free(runtime);

			exit (status);
		}
	}
}


void print_env(void)
{
	int i;

	while (environ[i])
	{
		puts(environ[i]);

		i++;
	}
}

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
