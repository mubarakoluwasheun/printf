#include "main.h"

/**
 * c_parser - parses c character specifier
 * @mods: pointer to the modifier
 * @ap: the arg list containing the character
 *
 * Return: the parsed string
 */
char *c_parser(mod_t *mods, va_list ap)
{
	char *ch = malloc(sizeof(char) * 2);

	(void)mods;
	if (ch == NULL)
		return (NULL);

	ch[0] = va_arg(ap, int);
	ch[1] = '\0';

	return (ch);
}

/**
 * symb_parser - parses the % character specifier
 * @mods: pointer to the modifier
 * @ap: the arg list containing the character
 *
 * Return: the parsed string
 */
char *symb_parser(mod_t *mods, va_list ap)
{
	(void)ap;
	(void)mods;
	return ("%");
}

/**
 * s_parser - parses the s specifier
 * @mods: pointer to the modifier
 * @ap: arg list containing the string
 *
 * Return: the parsed string
 */
char *s_parser(mod_t *mods, va_list ap)
{
	int len;
	char *str, *pad;

	str = va_arg(ap, char *);
	if (str == NULL)
		return ("(null)");

	len = _strlen(str);
	if (mods->prec != -1)
	{
		if (mods->prec < len)
			str[mods->prec] = '\0';
	}

	if (mods->width)
	{
		pad = create_pad(mods->width - _strlen(str), ' ');
		str = parse_minus(str, pad, mods);
	}

	return (str);
}
