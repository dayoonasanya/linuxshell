#include "shell.h"

void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/**
 * _memset - memory set.
 * @str: string.
 * @fill: put char into str.
 * @n: (no) of chars.
 */

void _memset(char *str, int fill, int n)
{
	int j;

	for (j = 0; j < n; j++)
		str[j] = fill;
}

/**
 * _memcpy - copy str to dest.
 * @dest: destination.
 * @src: source string.
 * @bytes: (no) of bytes.
 */

void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int j;

	for (j = 0; j < bytes; j++)
		dest[j] = src[j];
}

/**
 * _realloc - reallocate memory.
 * @ptr: pointer.
 * @old_size: old size for memory.
 * @new_size: new size for memory.
 * Return: new memory.
 */

void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *temp, *buffer;
	unsigned int j;

	if (ptr == NULL)
	{
		buffer = malloc(new_size);
		if (buffer == NULL)
			return (NULL);
		return (buffer);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		buffer = malloc(new_size * sizeof(char));
		temp = ptr;

		_memset(buffer, '\0', new_size);
		for (j = 0; j < old_size; j++)
			buffer[j] = temp[j];
		free(ptr);
		return (buffer);
	}
	return (ptr);
}

/**
 * _reallocdp - reallocate memory to dp.
 * @ptr: pointer.
 * @old_size: old size.
 * @new_size: new size.
 *
 * Return: return pointer.
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newpointer;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newpointer = malloc(sizeof(char *) * new_size);
	if (newpointer == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newpointer[j] = ptr[j];

	free(ptr);

	return (newpointer);
}
