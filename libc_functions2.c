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

int _atoi(const char *s)
{
	int m = 0;
	int result = 0;

	if (*s)
	{
		trim_start((char **)&s);
	}

	while (s[m] >= '0' && s[m] <= '9')
	{
		result = (result * 10) + (s[m] - '0');
		m++;
	}


	return (result);
}
