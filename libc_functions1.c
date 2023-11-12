#include "shell.h"

/**
 * _strcmp - compared two strings s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: it returns an integer
 * greater than 0  if  s1 is greater than s2.
 * less than 0 if s1 is smaller than s2.
 * or zeror if the strings are identical.
 *
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] && (s1[i] == s2[i]))
		i++;

	return (((int)s1[i]) - ((int)s2[i]));

}

/**
 * _strncmp - compared given bytes of  two strings s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: size of bytes to compare
 * Return: it returns an integer
 * greater than 0  if  s1 is greater than s2.
 * less than 0 if s1 is smaller than s2.
 * or zeror if the strings are identical.
 *
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	n = n - 1;

	while ((n) && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}

	return (((int)s1[i]) - ((int)s2[i]));

}


/**
 * _getenv - gets environment variable.
 * @name: the name of the variable
 * Return: pointer to the value of the variable
 */
char *_getenv(const char *name)
{
	int i = 0;
	int name_length = _strlen(name);

	if (!name)
		return (NULL);

	while (environ[i])
	{
		if (_strncmp(environ[i], name, name_length) == 0)
		{
			return ((char *)&(environ[i][_strcspn(environ[i], "=") + 1]));
		}

		i++;
	}

	return (NULL);
}


/**
 * _strdup: dublicates a string
 * @s: string to duplicate
 * Return: pointer to the duplicated string
 * or NULL if it fails to duplicate
 */
char *_strdup(const char *s)
{
	int i = 0;
	char *duplicate = NULL;

	if (!s)
		return (NULL);

	duplicate = (char *)malloc(sizeof(char) * _strlen(s) + 1);

	if (!duplicate)
		return (NULL);

	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}

	duplicate[i] = '\0';


	return (duplicate);
}

int _snprintf(char *str, size_t size, const char *format, ...)
{
	int i = 0;
	int full_length = 0;
	va_list list;
	va_start(list, format);

	while (format[i])
	{
		if (!size)
			break;

		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case 's':
					full_length += handle_string(list, &size, str);
					break;

				case 'c':
					full_length += handle_char(list, &size, str);
					break;
			}	
		}
		else

			full_length += handle_normal_char(&(format[i]), &size, str);

		i++;		
	}

	va_end(list);
	return (full_length);
}


