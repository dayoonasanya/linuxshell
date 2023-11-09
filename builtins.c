#include "shell.h"


void exit_shell(char *command, const char **argv)
{
	int status = 0;

	if (_strchr(command, ' ') == NULL)
	{
		exit(0);
	}
	else
	{
		command = _strrev(command);
		trim_start(&command);
		command = _strrev(command);
		status = atoi(command + 4);

		if (status == 0)
		{
			char *msg = ": invalid exit status";
			write(1, *argv, _strlen(*argv));
			puts(msg);
		}
		else
		{
			exit(status);
		}
	}
}

int builtin_command(char *command, const char **argv)
{
	int status = 0;

	if (_strncmp(command, "exit", 4) == 0)
	{
		status = 1;
		exit_shell(command, argv);
	}



	return (status);
}
