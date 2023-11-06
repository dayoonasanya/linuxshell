#include "shell.h"


/**
 * _strlen - finds the length of a string
 * @s: poointer to the string
 * Return: number of bytes in the string
 */

size_t _strlen(const char *s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strcspn - find the number of bytes in a string that
 * contains characters not in rejct.
 * @s: string to find number of bytes not in reject
 * @reject: string of characters not accepted
 * Return: size in bytes.
 * Description:  checks each character of s against the
 * characters in reject and if matches returns
 * the number of bytes not containing the character in
 * reject.
 */

size_t _strcspn(const char *s, const char *reject)
{
	size_t size = 0;
	size_t i = 0;

	while (*s != '\0')
	{
		i = 0;

		while (reject[i] != '\0')
		{
			if (reject[i] == *s)
			{
				return (size);
			}

			i++;
		}

		size++;
		s++;
	}

	return (size);
}

/**
 * _strchr - finds the character specified by c
 * @s: string which the character will be searched in
 * @c: character being searched in the string.
 * Return: pointer to the first occurence of the character
 */

char *_strchr(const char *s, int c)
{
	int i = 0;

	if  (s == NULL)
		return (NULL);

	while (s[i])
	{
		if  (s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}

	if (c == '\0')
		return ((char *)&(s[i]));

	return (NULL);
}

/**
 * _putchar - prints a character to stdout
 * @c: character to print
 * Return: the character printed
 */
int _putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);

	return (c);
}


/**
 * _puts - writes a string 's' and a newline to stdout
 * @s: string to write
 * Return: number of characters written
 */
int _puts(const char *s)
{
	int length = _strlen(s);

	if (length)
		write(STDOUT_FILENO, s, length);

	_putchar('\n');

	return (length + 1);
}

