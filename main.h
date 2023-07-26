#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#define BUFFER_SIZE 1024

/**
 * struct specifier_s - a conversion specifier
 *
 * @c: the character of the conversion specifier
 * @f: a poiner to a function that takes in va_list
 * objects as an argument and returns an int
 */
typedef struct specifier_s
{
	char c;
	int (*f)(va_list);
} specifier_t;

extern specifier_t specifiers[];

/**
 * struct buffer_s - Structure to hold the buffer
 * and its current index
 * @data: The buffer data
 * @index: The current index in the buffer
 */
typedef struct buffer_s
{
	char data[BUFFER_SIZE];
	int index;
} buffer_t;

void buffer_add_char(buffer_t *buffer, char c);
void buffer_flush(buffer_t *buffer);
int _printf(const char *format, ...);

/* Function prototypes */
int _printf(const char *format, ...);
int find_specifier(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

#endif
