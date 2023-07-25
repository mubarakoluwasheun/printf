#include "main.h"

int search_specifier(char * fmt, int *start, int *end);
char *(*search_parser(char c))(mod_t *mods, va_list ap);
int is_specifier(char c);

/**
 * parse_input - parses the input format string
 * @fmt: the input string
 * @ap: the variable argument list
 *
 * Return: the parsed string
 */
char *parse_input(const char *fmt, va_list ap)
{
	mod_t *mods;
	char c;
	char *tmp, *f;
	int len, start = 0, end, result;
	char *(*parse)(mod_t *mods, va_ist ap);

	while (1)
	{
		result = search_specifier(fmt, &start, &end);
		if (result == 0)
			break;

		tmp = fmt;
		c = tmp[end];
		tmp[start] = '\0';
		tmp[end] = '\0';
		fmt = str_concat("", tmp);
		parse = search_parser(c);
		initialize_modifiers(mods);
		check_modifiers(tmp + start + 1, mods);
		substr = parse(mods, ap);
		f = fmt;
		fmt = str_concat(fmt, substr);
		free(f);
		tmp[end + 1] = c;
		f = fmt;
		fmt = str_concat(fmt, tmp + end + 1);
		free(f);
	}
	if (start == -1)
		return (NULL);

	return (fmt);
}

/**
 * search_specifier - searches the indices of the start and end of a specifier
 * @fmt: the format string
 * @start: pointer to the start of the specifier
 * @end: pointer to the end of the specifier
 *
 * Return: the value of start if spec found, 0 if not
 */
int search_specifier(char *fmt, int *start, int *end)
{
	int i = *start;

	*start = -1;
	*end = -1;
	for (; fmt[i]; ++i)
	{
		if (fmt[i] == '%')
		{
			*start = i++;
			break;
		}
	}

	if (*start == -1)
	{
		*start = 0;
		return (0);
	}
	else
	{
		for (; fmt[i]; ++i)
		{
			if (is_specifier(fmt[i]))
			{
				*end = i;
				break;
			}
		}

		if (*end == -1)
		{
			*start = -1;
			return (0);
		}
	}
	return (*start);
}

/**
 * search_parser - searches for the appropriate parser for the specifier
 * @c: the specifier
 *
 * Return: pointer pointing to the parser
 */
char *(*search_parser(char c))(mod_t *mods, va_list ap)
{
	spec_t specs[] = {
		{'c', c_parser},
		{'%', symb_parser},
		{'s', s_parser},
		{'d', i_parser},
		{'i', i_parser},
		{'b', b_parser},
		{'x', x_parser},
		{'X', X_parser},
		{'o', o_parser},
		{'u', u_parser},
		{'p', p_parser},
		{'S', S_parser},
		{'r', r_parser},
		{'R', R_parser},
		NULL
	};
	int i;

	for (i = 0; specs[i]; ++i)
	{
		if (c == specs[i].spec)
			return (specs[i].parser);
	}

	return (NULL);
}

/**
 * is_specifier - checks if a character is a conversion specifier
 * @c: the conversion spec
 *
 * Return: 1 if true, 0 otherwise
 */
int is_specifier(char c)
{
	char *specs = "c%sdibxXoupSrR";

	while (*specs)
	{
		if (*specs == c)
			return (1);

		specs++;
	}

	return (0);
}
