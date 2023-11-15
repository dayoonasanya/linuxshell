
#include "shell.h"

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

				case 'd':
					{
						char buffer[256];
						int i = 0;
						int num = va_arg(args, int);
						_itoa(num, buffer, 10);

						while (buffer[i] && written < capacity)
						{
							*str++ = buffer[i];
							i++;
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


char *_itoa(int num, char *str, int base)
{
	int power = 1;
	int og_number = num;

	while (num >= 10)
	{
		power *= 10;
		num /= 10;
	}

	num = og_number;

	if (base == 10)
	{
		while(power >= 1)
		{
			*str++ = (num / power) + '0';
			num %= power;
			power /= 10;
		}

		*str = '\0';
	}

	return (str);
}
