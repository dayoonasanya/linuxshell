#include "shell.h"

void command_not_found(char *command, const  char **argv)
{
	if (command)
		perror(*argv);
}

void find_path(char *command, const char **argv)
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

		snprintf(full_path, full_length, "%s/%s", path, cmd);
		if (access(full_path, F_OK) == 0)
		{
			found = 1;
			if (strchr(command, ' '))
			{

				snprintf(full_path, full_length, "%s/%s", path, command);
				execute_command_args_with_path(full_path, argv);
			}
			else
				execute_command_no_args_with_path(full_path, argv);

			break;
		}

		path = strtok(NULL, ":");
		free(full_path);
		full_path = NULL;
	}
	if (!found)
		command_not_found(command, argv);


	free(get_path);
	free(cmd_cpy);
	free(full_path);
}
