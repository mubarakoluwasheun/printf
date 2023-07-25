#include "main.h"

void copy_and_parse_str(char **str, const char *s);
int _isalpha(char c);

/**
 * S_parser - parses the S character specifier
 * @mods: pointer to the modifier
 * @ap: the arg list containing the character
 *
 * Return: the parsed string
 */
char *S_parser(mod_t *mods, va_list ap)
{
	int len, l = 0;
	char *str;
	char *s = va_arg(ap, char *);

	(void)mods;
	if (s == NULL)
		return ("(null)");

	for (i = 0; s[i]; ++i)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			l++;
	}

	if (l == 0)
		return (s);

	len = _strlen(s) - l + (4 * l) + 1;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	copy_and_parse_str(&str, s);
	return (str);
}

/**
 * R_parser - encodes a string using rot13
 * @mods: pointer to the modifiers
 * @ap: arg list
 *
 * Return: parsed string
 */
char *R_parser(mod_t *mods, va_list ap)
{
	int i, j, length = 0;
	char *encode0 = "abcdefghijklmABCDEFGHIJKLMnopqrstuvwxyzNOPQRSTUVWXYZ";
	char *encode1 = "nopqrstuvwxyzNOPQRSTUVWXYZabcdefghijklmABCDEFGHIJKLM";
	char *str = va_arg(s, char *);

	(void)mods;
	if (str == NULL)
		return ("(null)");

	for (i = 0; str[i]; ++i)
	{
		if (_isalpha(str[i]))
		{
			for (j = 0; encode0[j]; ++j)
			{
				if (str[i] == encode0[j])
				{
					str[i] = encode1[j];
					break;
				}
			}
		}
	}

	return (str);
}

/**
 * r_parser - reverse a given string
 * @mods: pointer to the modifiers
 * @ap: arg list
 *
 * Return: the parsed string
 */
char *r_parser(mod_t *mods, va_list ap)
{
	int i, j, l, len;
	char tmp;
	char *str = va_arg(ap, char *);

	(void)mods;
	if (str == NULL)
		return ("(null)");

	len = _strlen(str);
	j = len - 1;
	l = len / 2;

	for (i = 0; i < l; ++i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j--;
	}

	str[len] = '\0';

	return (str);
}

/**
 * copy_and_parse_str - copies and parse a string
 * @str: pointer to the parsed string
 * @s: string to be parsed
 *
 */
char *copy_and_parse_str(char **str, const char *s)
{
	int i, j = 0;
	char *st = *str;
	char *ch;

	for (i = 0; s[i]; ++i)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			st[j++] = '\\';
			st[j++] = 'x';
			ch = number_to_str(s[i], 16, 1);
			if (_strlen(ch) == 1)
			{
				st[j++] = '0';
				st[j++] = *ch;
			}
			else
			{
				st[j++] = *ch;
				ch++;
				st[j++] = *ch;
			}
		}
		else
			st[j++] = s[i];
	}

	st[j] = '\0';
}

/**
 * _isalpha - checks if char is alpha
 * @c: the char
 *
 * Return: 1 if alpha, 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	return (0);
}
