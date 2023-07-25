#include "main.h"

/**
 * create_pad - creates a 0 or ' ' pad
 * @c: pad character
 * @pad_len: pad length
 * Return: pointer to the pad
 */
char *create_pad(char c, int pad_len)
{
	int i, len = pad_len;
	char *pad = "";

	if (len > 0)
	{
		pad = malloc(sizeof(char) * (len + 1));
		if (pad == NULL)
			return (NULL);

		for (i = 0; i < len; ++i)
			pad[i] = c;

		pad[i] = '\0';
	}

	return (pad);
}

/**
 * parse_width - parses the width specifier
 * @str: the str to be parsed
 * @mods: pointer to modifiers
 *
 * Return: pad created
 */
char *parse_width(const char *str, mod_t *mods)
{
	char c;
	int l;
	char *pad = "";

	l = mods->width - _strlen(str);
	if (l > 0)
	{
		if (mods->zero)
			c = '0';
		pad = create_pad(c, l);
	}

	return (pad);
}

/**
 * parse_precision - parses the precision specifier
 * @str: the str to be parsed
 * @mods: pointer to modifiers
 *
 * Return: the parsed string
 */
char *parse_precision(char *str, mod_t *mods)
{
	int l;
	char *pad = "";

	if (mods->prec == 0)
		str = "";
	else
	{
		l = mods->prec - _strlen(str);
		if (l > 0)
		{
			pad = create_pad('0', l);
			str = str_concat(pad, str);
		}
	}

	return (str);
}
