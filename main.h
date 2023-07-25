#ifndef PRINTF
#define PRINTF

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * struct mod_s - structure for modifiers
 * @plus: + flag
 * @hash: # flag
 * @zero: 0 flag
 * @minus: - flag
 * @space: ' ' flag
 * @width: width modifier
 * @prec: precision modifier
 * @len: length modifier
 *
 */
typedef struct mod_s
{
	int plus;
	int hash;
	int zero;
	int minus;
	int space;
	int width;
	int prec;
	char len;
} mod_t;

/**
 * struct spec_s - structure for specifier handlers
 * @spec: the specifier character
 * @parser: the specifier handler
 *
 */
typedef struct spec_s
{
	char spec;
	char *(*parser)(mod_t *, va_list);
} spec_t;

int _printf(const char *format, ...);

/* string_util */
int _putchar(char c);
int _puts(const char *str);

#endif /* PRINTF */
