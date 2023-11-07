#include "shell.h"

void find_path(char *command)
{
	char *cmd_cpy = _strdup(command);
	char *cmd = strtok(cmd_cpy, " ");
	int cmd_length = _strlen(command);
	int full_length = 0;
	char *full_path = NULL;
	char *path = strtok(_getenv("PATH"), ":");
	int found = 0;

	while (path)
	{

		full_length = (cmd_length + _strlen(path)) + 2;
		full_path = malloc(sizeof(char) + full_length);

		snprintf(full_path, full_length, "%s/%s", path, 	cmd);
	       if (access(full_path, F_OK))
	       {
			/*call handle with args*/
		       found = 1;
	       }
	     
		path = strtok(NULL, ":");
	}

	if (!found)
		/** print error */

	
	free(cmd_cpy);
	free(full_path);

}
