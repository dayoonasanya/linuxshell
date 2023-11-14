#include "shell.h"


/**
 * find_path- finds path  where command is located
 * @command: command string
 * @argv: command line args
 * @runtime: pointer to the runtime_t struct for shell exec info
 * Description: if the path is found
 * it executes the command with its full path
 * if not found it prints error specified in
 * command not found function
 */
void find_path(char *command, const char **argv, runtime_t *runtime)
{
	char *cmd_cpy = _strdup(command);
	char *cmd = strtok(cmd_cpy, " ");
	int cmd_length = _strlen(command);
	int full_length = 0;
	char *full_path = NULL;
	char *get_path = _strdup(_getenv("PATH"));
	char *path = strtok(get_path, ":");
	int found = 0;

	while (path)
	{
		full_length = (cmd_length + _strlen(path)) + 2;
		full_path = malloc(sizeof(char) + full_length);

		_snprintf(full_path, full_length, "%s/%s", path, cmd);
		if (access(full_path, F_OK) == 0)
		{
			found = 1;
			if (strchr(command, ' '))
			{
				_snprintf(full_path, full_length, "%s/%s", path, command);
				execute_command_args_with_path(full_path, argv, runtime);
			}
			else
				execute_command_no_args_with_path(full_path, argv, runtime);

			break;
		}

		path = strtok(NULL, ":");
		free(full_path);
		full_path = NULL;
	}
	if (!found)
		print_command_error(command, argv, runtime);

	free(get_path);
	free(cmd_cpy);
	free(full_path);
}
