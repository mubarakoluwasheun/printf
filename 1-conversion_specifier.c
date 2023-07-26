#include "main.h"

/**
 * print_percent - prints a percent character
 * @args: list(void) of arguments
 *
 * Return: the number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;

	write(1, "%", 1);
	return (1);
}

/**
 * print_char - prints a character
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	if (c == '\0')
		write(1, "(null)", 1);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
