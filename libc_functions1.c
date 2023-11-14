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
 * Description: returns a pointer to the requested
 * environment variable or NULL if not found
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
 * _strdup -  dublicates a string
 * @s: string to duplicate
 * Description: copies the contents of 's'
 * to a new location and null terminates it.
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

/**
 * _snprintf - prints formated text to a buffer
 * @str: buffer to store formated text
 * @size: sizeof bytes to write
 * @format: format specifiers string
 * @...:  variadic arguments
 * Return: number of bytes that could have been
 * written if the buffer was large enough
 * or number  of all bytes written if all is written
 i*/
int _vsnprintf(char *str, size_t size, const char *format, va_list args)
{
        int written = 0;
        int capacity = size - 1;

        while (*format && written < capacity)
        {
                if (*format == '%')
                {
                        ++format;

                        switch (*format)
                        {
                                case 's':
                                {
                                char *arg = va_arg(args, char *);

                                        while (*arg && written < capacity)
                                        {
                                                *str++ = *arg++;
                                                ++written;
                                        }
                                                break;
                                }
                                default:
                                        *str++ = *format;
                                        ++written;
                                        break;
                        }
                }
                else
                {
                        *str++ = *format;
                        ++written;
                }
                ++format;
        }
        *str = '\0';
        return (written);
}

/**
 * _snprintf - Formats a string and writes it to a buffer.
 * @buffer: The buffer to write the formatted string.
 * @size: The size of the buffer.
 * @format: The format string.
 *
 * Return: The number of characters written, excluding the null terminator.
 */
int _snprintf(char *buffer, size_t size, const char *format, ...)
{
        va_list args;
        int result;

        va_start(args, format);
        result = _vsnprintf(buffer, size, format, args);
        va_end(args);

        return (result);
}
