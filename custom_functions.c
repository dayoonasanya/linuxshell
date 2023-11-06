#include "shell.h"

/**
 * trim_start - removes white space  from the start of string
 * @s: pointer to the string to be  trimed
 * Description: removes all white spaces at the beggining that comes
 * before a normal character
 */


void trim_start(char **s)
{
	int i = 0;
	int spaces = 0;

	while (((*s)[spaces]) && (((*s)[spaces] == ' ') || ((*s)[spaces] == '\t')))
		spaces++;

	if (spaces > 0)
	{
		while ((*s)[spaces + i])
		{
			(*s)[i] = (*s)[spaces + i];
			i++;
		}

		(*s)[i] = '\0';
	}
}
