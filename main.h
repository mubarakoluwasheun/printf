#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct specifier_s - a conversion specifier
 *
 * @c: the character of the conversion specifier
 * @f: a pointer to a function that takes in va_list
 * objects as an argument and returns an int
 */

typedef struct specifier_s
{
	char c;
	int (*f)(va_list);
} specifier_t;

specifier_t specifiers[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
	{'%', print_percent},
	{0, NULL}
};

extern specifier_t specifiers[];

/* Function prototypes */
int _printf(const char *format, ...);
int find_specifier(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(va_list args);

#endif
