#include "main.h"

/**
 *checker- checkers.
 *@cmd: command
 *@buf: buffer.
 *Return: 0 or 1.
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
