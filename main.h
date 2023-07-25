#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct specifier_s
{
    char c;
    int (*f)(va_list);
} specifier_t;

extern specifier_t specifiers[];

/* Function prototypes */
int _printf(const char *format, ...);
int find_specifier(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(va_list args);

#endif
