#include "shell.h"

char **tokenize(char *line);
int delim_count(char *string, char delim);

/**
 * delim_count - delim count.
 * @str: string.
 * @delim: delimiter.
 *
 * Return: words.
 */

int delim_count(char *str, char delim)
{
	int j = 0, wrds = 0;

	if (str)
	{
		for (; str[j] != '\0'; j++)
		{
			if (str[j] == delim)
			wrds++;
		}
		wrds++;
	}
	return (wrds);
}

/**
 * tokenize - separate sting.
 * @line: line.
 *
 * Return: return tokens.
 */
char **tokenize(char *line)
{
	int bufsize = delim_count(line, ' '), i = 0;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * (bufsize + 1));
	if (!tokens)
	{
		free(tokens);
		perror("Allocation Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
