#include "main.h"

/**
 * find_specifier - finds a conversion specifier in the specifiers array
 * @c: the character representing the conversion specifier
 *
 * Return: the index of the conversion specifier in the specifiers array,
 * or -1 if not found
 */
int find_specifier(char c)
{
	int i;

	for (i = 0; specifiers[i].c != 0; i++)
	{
		if (specifiers[i].c == c)
		{
			return (i);
		}
	}
	return (-1);
}
