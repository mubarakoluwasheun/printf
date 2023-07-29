#include "main.h"

/**
 * format_pointer - Formats a pointer value into a string
 * @ptr: The pointer value
 * @str: The buffer to store the formatted string
 *
 * Return: The number of characters written to the buffer
 */
int format_pointer(void *ptr, char *str)
{
	unsigned long p = (unsigned long)ptr;
	char *hex = "0123456789abcdef";
	int i = 0, j;

	str[i++] = '0';
	str[i++] = 'x';

	for (j = (sizeof(p) << 3) - 4; j >= 0; j -= 4)
		str[i++] = hex[((p >> j) & 0x0f)];

	str[i] = '\0';

	return (i);
}

/**
 * print_pointer - Prints a pointer
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;
	char *str;

	if (ptr == NULL)
	{
		str = "(nil)";
		count += write(1, str, 5);
	}
	else
	{
		str = malloc(20);
		count += format_pointer(ptr, str);
		count += write(1, str, count);
		free(str);
	}
	return (count);
}
