#include  "main.h"

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
