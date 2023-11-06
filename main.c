







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
	(void) ac;
	printf("=>%s", _getenv("PWD"));
	start_shell((const char **)av);

	return (0);
}