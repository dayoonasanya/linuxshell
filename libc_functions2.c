#include "shell.h"


char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strcpy - copy string.
 * @dest: destination.
 * @src: source string.
 *
 * Return: dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenate string.
 * @dest: dest string.
 * @src: source string.
 *
 * Return: dest.
 */

char *_strcat(char *dest, const char *src)
{
	char *_dest;
	const char *_src;

	_dest = dest;
	_src =  src;

	while (*_dest != '\0')
		_dest++;

	while (*_src != '\0')
		*_dest++ = *_src++;
	*_dest = '\0';
	return (dest);
}

/**
 * _strncat - concatenate string.
 * @dest: destination.
 * @src: source string.
 * @n: (n) bytes.
 *
 * Return: dest.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
