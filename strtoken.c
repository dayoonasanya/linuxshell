#include "shell.h"


int _delim(char c, char *delim);
char *_strtok(char *line, char *delim);


/**
 * _delim - delimeter.
 * @c: character.
 * @delim: delimeter.
 *
 * Return: 0 or 1.
 */

int _delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _strtok - string & delimeters.
 * @line: pointer.
 * @delim: delimeter.
 *
 * Return: token.
*/

char *_strtok(char *line, char *delim)
{
	int j;
	char *string;
	char *copy;

	if (line != NULL)
		string = line;
	for (; *string != '\0'; string++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*string == delim[j])
			break;
		}
		if (delim[j] == '\0')
			break;
	}
	copy = string;
	if (*copy == '\0')
		return (NULL);
	for (; *string != '\0'; string++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*string == delim[j])
			{
				*string = '\0';
				string++;
				return (copy);
			}
		}
	}
	return (copy);
}