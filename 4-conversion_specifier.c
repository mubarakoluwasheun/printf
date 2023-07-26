#include "main.h"

/**
 * print_unsigned - converts a value to an unsigned int
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[11];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = '0' + n % 10;
		n /= 10;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}

/**
 * print_octal - converts a value to an octal
 * @args: list of argument
 *
 * Return: the number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[11];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = '0' + n % 8;
		n /= 8;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}

/**
 * print_hex_lower - converts a value to a lower hexadecimal
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */

int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[11];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		if (n % 16 < 10)
			buffer[i++] = '0' + n % 16;
		else
			buffer[i++] = 'a' + n % 16 - 10;
		n /= 16;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}

/**
 * print_hex_upper - converts a value to an upper hexadecimal
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */

int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[11];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		if (n % 16 < 10)
			buffer[i++] = '0' + n % 16;
		else
			buffer[i++] = 'A' + n % 16 - 10;
		n /= 16;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}
