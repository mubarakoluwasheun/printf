#include "main.h"

/**
 * u_parser - parses the u specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *u_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str, *pad = "";

	if (mods->len == 'l')
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, long int);

	str = number_to_str(num, 10, 0);
	if (mods->prec)
		str = parse_precision(str, mods);

	if (mods->width)
		pad = parse_width(str, mods);

	if (mods->minus)
		str = parse_minus(str, pad, mods);

	return (str);
}

/**
 * o_parser - parses the o specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *o_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str, *pad = "";

	if (mods->len == 'l')
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, long int);

	str = number_to_str(num, 8, 0);
	if (mods->zero)
	{
		if (mods->width)
		{
			if (mods->hash)
				mods->width -= 2;
			
	if (mods->hash)
		str = parse_hash(str, "0");

	if (mods->prec)
		str = parse_precision(str, mods);

	if (mods->width)
		pad = parse_width(str, mods);

	if (mods->minus)
		str = parse_minus(str, pad, mods);

	return (str);
}

/**
 * x_parser - parses the x specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *x_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str, *pad = "";

	if (mods->len == 'l')
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, long int);

	str = number_to_str(num, 16, 0);
	if (mods->prec)
		str = parse_precision(str, mods);

	if (mods->hash)
		str = parse_hash(str, "0x");

	if (mods->width)
		pad = parse_width(str, mods);

	if (mods->minus)
		str = parse_minus(str, pad, mods);

	return (str);
}

/**
 * X_parser - parses the X specifier
 * @mods: pointer to the modifiers
 * @ap: the arg list
 *
 * Return: the parsed string
 */
char *X_parser(mod_t *mods, va_list ap)
{
	unsigned long int num;
	char *str, *pad = "";

	if (mods->len == 'l')
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, long int);

	str = number_to_str(num, 16, 1);
	if (mods->prec)
		str = parse_precision(str, mods);

	if (mods->hash)
		str = parse_hash(str, "0X");

	if (mods->width)
		pad = parse_width(str, mods);

	if (mods->minus)
		str = parse_minus(str, pad, mods);

	return (str);
}
