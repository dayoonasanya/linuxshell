#include "shell.h"


char *_strrev(char *s)
{
	int length = _strlen(s);
	int i = 0;
	int temp = 0;

	while (i < length / 2)
	{
		temp = s[i];
		s[i] = s[length -1 -i];
		s[length - 1 - i] = temp;
		i++;
	}

	return s;
}
