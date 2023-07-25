#include "main.h"

/**
 * b_parser - parses the b specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *b_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str;

	(void)mods;
	num = va_arg(ap, unsigned long int);
	str = number_to_str(num, 2, 0);

	return (str);
}

/**
 * p_parser - parses the p specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *p_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str;

	(void)mods;
	num = (unsigned long int)va_arg(ap, void *);
	if (!num)
		return ("(nil)");

	str = number_to_str(num, 16, 0);
	str = str_concat("0x", str);

	return (str);
}

/**
 * i_parser - parses the i and d specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *i_parser(mod_t *mods, va_list ap)
{
	long int num;
	unsigned long int n = 0;
	char *s;

	if (mods->len)
		n = va_arg(integer, long int);

	else
		n = va_arg(integer, int);

	num = n;
	if (num < 0)
	{
		num *= -1;
		n = num;
		negative = 1;
	}
