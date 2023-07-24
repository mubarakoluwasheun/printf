#include "main.h"

/**
 * print_percent - prints a percent character
 *
 * Return: the number of characters printed
 */
int print_percent(void)
{
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

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
