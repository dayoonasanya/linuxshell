#include "shell.h"

/**
 * execute - executes given programme
 * @av: argument vector which contains
 * the programme to execute and
 * its arguments if any
 *
 * @argv: pointer to command line arguments
 */
void execute(char **av, const char **argv)
{

	pid_t execute_process = fork();
	int i = 0;


	if (execute_process == -1)
	{
		perror(argv[0]);
	}
	else if (execute_process == 0)
	{
		if (execve(*av, av, environ) == -1)
		{
			perror(argv[0]);
		}
	}
	else if (execute_process > 0)
	{
		wait(NULL);

		while (av[i])
		{
			free(av[i]);
			i++;
		}

		free(av);
	}
}


/**
 * execute_command_no_args_with_path - execute command given path
 * @command: pointer to a string comtaining the command
 * @argv: pointer to command line args strings
 * Description: execute with no arguments
 */

void execute_command_no_args_with_path(char *command, const char **argv)
{
	char **argumentVector = (char **)malloc(sizeof(char *) * 2);

	argumentVector[0] = strdup(command);
	argumentVector[1] = NULL;

	execute(argumentVector, argv);

}


/**
 * find_number_of_strings - finds number of strings
 * @command: the command pointer
 * Description: the strings that are separated by
 * a space
 * a tab
 *
 * Return: number of strings/words
 */
int  find_number_of_strings(char *command)
{
	int number_of_strings = 0;
	char *token = strtok(command, " \t");

	while (token)
	{
		number_of_strings++;
		token = strtok(NULL, " \t");
	}

	free(command);

	return (number_of_strings);

}

/**
 * execute_command_args_with_path -initialise the execution
 * of a command with arguments
 * @command: command to execute
 * @argv: command line arguments
 */
void execute_command_args_with_path(char *command, const char **argv)
{
	char *token = NULL;
	int i = 0;
	char *command_dup = strdup(command);
	char **av = (char **) malloc(sizeof(char *) *
			find_number_of_strings(strdup(command)) + 1);

	token = strtok(command_dup, " \t");

	if (token)
	{
		while (token)
		{
			av[i] = strdup(token);
			token = strtok(NULL, " \t");
			i++;
		}

		av[i] = NULL;

		free(command_dup);

		execute(av, argv);
	}

}
