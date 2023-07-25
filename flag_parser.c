#include "main.h"

/**
 * parse_minus - parse the - flag
 * @str: the string to parse
 * @pad: the pad
 * @mods: pointer to modifiers
 *
 * Return: the padded string
 */
char *parse_minus(char *str, char *pad, mod_t *mods)
{
	if (mods->minus)
		str = str_concat(str, pad);
	else
		str = str_concat(pad, str);

	if (*pad)
		free(pad);

	return (str);
}
