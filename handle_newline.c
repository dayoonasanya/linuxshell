#include "shell.h"

void handle_newline(char *str);
int _atoi(char *s);

/**
 * _atoi - string to integer.
 * @s: target string.
 *
 * Return: string.
*/

int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}

/**
 *handle_newline - remove newline.
 *@str: string source.
 *
 *Return: return nothing.
 */
void handle_newline(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			break;
		j++;
	}
	str[j] = '\0';
}
