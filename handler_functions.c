#include "shell.h"

int handle_string(va_list list, size_t *size, char *str)
{
	char *s = va_arg(list, char *);
	int length = _strlen(s);
	int index = _strlen(str);
	int i = 0;

	while (((*size) - 1) && s[i])
	{
		str[index] = s[i];
		i++;
		index++;
		(*size)--;
	}

	str[index] = '\0';

	return (length);
}


int handle_char(va_list list, size_t *size, char *str)
{
	int c = va_arg(list, int);
	int length = _strlen(str);

	if ((*size) - 1)
	{
		str[length] = c;
	}

	(*size)--;

	str[length + 1] = '\0';
	return (1);
}

int handle_normal_char(const char *format, size_t *size, char *str)
{
	int length = _strlen(str);

	if ((*size) - 1)
	{
		str[length] = *format;
	}
	
	(*size)--;
	
	str[length + 1] = '\0';

	return (1);
}
