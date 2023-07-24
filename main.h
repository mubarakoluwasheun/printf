#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int find_specifier(char c);
int print_percent(void);

typedef struct specifier_s
{
	char c;
	int (*f)(va_list);
} specifier_t;

#endif
