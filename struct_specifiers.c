#include "main.h"

specifier_t specifiers[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
	{'%', print_percent},
	{'b', print_binary},
	{0, NULL}
};
