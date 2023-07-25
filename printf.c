#include "main.h"

/**
 * _printf - custom implementation of the printf
 * function
 * @format: character string composed of zero or
 * more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	buffer_t buffer = {{0}, 0};
	int i, j;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			j = find_specifier(format[i]);
			if (j >= 0)
				specifiers[j].f(args, &buffer);
		}
		else
			buffer_add_char(&buffer, format[i]);
	}
	buffer_flush(&buffer);

	va_end(args);
	return (buffer.index);
}
