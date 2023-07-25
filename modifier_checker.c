#include "main.h"

void check_numbers(mod_t *mods, va_list ap, char spec);

/**
 * initialize_modifiers - initializes the member of a mod_t type
 * @mods: the mod_t variable to initialize
 *
 */
void initialize_modifiers(mod_t *mods)
{
	mods->plus = 0;
	mods->hash = 0;
	mods->minus = 0;
	mods->space = 0;
	mods->zero = 0;
	mods->width = 0;
	mods->prec = -1;
	mods->len = '\0';
}

/**
 * check_modifiers - checks and sets modifier in the input specifier
 * @spec: the input specifier
 * @mods: pointer to modifiers
 * @ap: arg list of the format string
 *
 */
void check_modifiers(char *spec, mod_t *mods, va_list ap)
{
	int i;

	if (!spec[0])
		return;

	for (i = 0; spec[i], ++i)
	{
		if ((spec[i] <= '9' && spec[i] >= '0')
		    || spec[i] == '*' || spec[i] == '.')
			check_numbers(mods, ap, spec[i]);

		else if (spec[i] == 'l' || spec[i] == 'h')
			mods->len = spec[i];
		else if (spec[i] == '#')
			mods->hash = spec[i];
		else if (spec[i] == '-')
			mods->minus = spec[i];
		else if (spec[i] == '+')
			mods->plus = spec[i];
		else if (spec[i] == ' ')
			mods->space = spec[i];
	}

	if (mods->minus || (mods->prec != -1))
		mods->zero = 0;

	if (mods->plus)
		mods->space = 0;
}

/**
 * check_numbers - check the modifiers that has to do with numbers
 * @mods: pointer to the modifiers
 * @ap: the arglist
 * @spec: the specifier to check for
 *
 */
void check_numbers(mod_t *mods, va_list ap, char spec)
{
	if (mods->prec != -1 || spec == '.')
	{
		if (spec == '.')
			mods->prec = 0;
		else if (spec == '*')
			mods->prec = va_arg(ap, int);
		else
		{
			mods->prec *= 10;
			mods->prec += (spec - '0');
		}
	}
	else if (mods->width || mods->zero)
	{
		if (spec == '*')
			mods->width = va_arg(ap, int);
		else
		{
			mods->width *= 10;
			mods->width += (spec - '0');
		}
	}
	else if (spec == '0')
		mods->zero = 1;
}
