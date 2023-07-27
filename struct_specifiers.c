#include "main.h"

specifier_t specifiers[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
	{'%', print_percent},
	{'b', print_binary},
	{'u', print_unsigned},
	{'o', print_octal},
	{'x', print_hex_lower},
	{'X', print_hex_upper},
	{'S', print_custom_string},
	{'p', print_pointer},
	{0, NULL}
};
