#include "main.h"

/**
 * _printf - prints formatted characters
 * @format: the character string to be printed
 *
 * Return: number of characters printed, -1 if failed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	str = parse_input(format, ap);
	va_end(ap);
	if (str == NULL)
		return (-1);

	return (_puts(str));
}
