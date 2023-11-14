#include "shell.h"

/**
 * print_command_error -  prints error message when command is not found
 * @command: pointer to command
 * @argv:  cmd line args pointer
 * @runtime: pointer to runtime_t struct
 * Description: prints error to stderr
 */

void print_command_error(char *command, const  char **argv, runtime_t *runtime)
{
	char msg[256];

	if (*command == '/' || (*command == '.' && command[1] == '/'))
	{

		snprintf(msg, sizeof(msg), "%s: %d: %s", *argv, runtime->error_number,
				command);
		perror(msg);
	}
	else
	{
		snprintf(msg, sizeof(msg), "%s: %d: %s: not found", *argv,
				runtime->error_number, command);
		puts(msg);
	}


	runtime->error_number++;
}

