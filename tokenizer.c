#include "shell.h"
#include <string.h>
#include <stdarg.h>

char **tokenize(char *line);
int delim_count(char *stri, char delim);

/**
 * delim_count - delim count.
 * @str: string.
 * @delim: delimiter.
 *
 * Return: words.
 */

int delim_count(char *str, char delim)
{
	int w = 0, n = 0;

	if (str)
	{
		for (; str[n] != '\0'; n++)
		{
			if (str[n] == delim)
			w++;
		}
		w++;
	}
	return (w);
}

/**
 * tokenize - separate sting.
 * @line: line.
 *
 * Return: return tokens.
 */
char **tokenize(char *line)
{
	int bufferz = delim_count(line, ' '), n = 0;
	char *t2 = NULL;
	char **t1 = NULL;

	t1 = malloc(sizeof(char *) * (bufferz + 1));
	if (!t1)
	{
		free(t1);
		perror("Failed to allocate");
		exit(EXIT_FAILURE);
	}
	t2 = _strtok(line, SEPARATE_STRING);
	while (t2 != NULL)
	{
		t1[n] = t2;
		n++;
		t2 = _strtok(NULL, SEPARATE_STRING);
	}
	t1[n] = NULL;
	return (t1);
}
