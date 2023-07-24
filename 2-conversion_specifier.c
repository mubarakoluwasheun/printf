#include "main.h"

/**
 * print_int - prints an integer
 * @args: list of arguments
 *
 * Return: the number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[11];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
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
