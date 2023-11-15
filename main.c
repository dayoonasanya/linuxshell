#include "shell.h"

/**
 * main - run the code
 * @ac: number of cmdline arguments
 * @av: pointer to cmdline arguments strings
 * Description: runs code and all associated functions
 * Return: 0;
 */

int main(int ac, char **av)
{
	int status = 0;

	runtime_t *runtime = malloc(sizeof(runtime_t));

	runtime->error_number = 1;
	runtime->error_msg = NULL;
	runtime->last_proc_exit_status = 0;

	(void) ac;
	/**setenv("Ctrl_C", "not_set", 0);*/
	start_shell((const char **)av, runtime);
	
	if (runtime->error_number > 1)
	{
		status = 127;
	}

	free_resources(runtime);

	return (status);
}
