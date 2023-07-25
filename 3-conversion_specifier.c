#include "main.h"

/**
 * print_binary - converts a value to a binary string
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[33];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = '0' + n % 2;
		n /= 2;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
