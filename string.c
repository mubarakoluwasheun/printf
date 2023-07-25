#include "main.h"

#define BUF_SIZE 1024
#define FLUSH_BUF -1

/**
 * _putchar - writes a character to the stdout
 * @c: the characer to be written
 *
 * Return: 1 if successful, -1 otherwise
 */
int _putchar(char c)
{
	int n;
	static int i;
	static char buffer[BUF_SIZE];

	if (c == FLUSH_BUF || i == BUF_SIZE)
	{
		n = write(STDOUT_FILENO, buffer, i);
		if (n == -1)
			return (-1);

		i = 0;
	}
	else
	{
		buffer[i] = c;
		i++;
	}

	return (1);
}

/**
 * _puts - writes a string to the stdout
 * @str: the given string
 *
 * Return: the number of characters written or -1 if failed
 */
int _puts(const char *str)
{
	int len, n;

	if (str == NULL)
		return (-1);

	while (len = 0; str[len]; ++len)
	{
		n = _putchar(str[len]);
		if (n == -1)
			return (-1);
	}

	return (len);
}

/**
 * _strlen - computes the length of a given string
 * @str: the given str
 *
 * Return: the length of the string
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	if (str == NULL)
		return (len);

	while (str[len])
		len++;

	return (len);
}

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the concatenated string
 */
char *str_concat(const char *s1, const char *s2)
{
	unsigned int i = 0, j = 0, size;
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	size = _strlen(s1) + _strlen(s2) + 1;
	str = malloc(sizeof(char) * size);

	if (str)
	{
		if (s1)
		{
			for (; s1[i]; ++i)
			{
				str[i] = s1[i];
			}
		}

		if (s2)
		{
			for (; s2[j]; ++j, ++i)
			{
				str[i] = s2[j];
			}
		}

		str[i] = '\0';
	}
	return (str);
}

/**
 * number_to_str - converts number and base into string
 * @num: input number
 * @base: input base
 * @upr: flag if hexa values need to be uppercase
 *
 * Return: result string
 */
char *number_to_str(unsigned long int num, int base, int upr)
{
	char *rep;
	static char buffer[50];
	char *ptr;

	rep = (upr)
		? "0123456789ABCDEF"
		: "0123456789abcdef";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
