#include "main.h"

/**
 * format_non_printable_char - Formats a non-printable
 * character as a string
 * @buffer: The buffer to store the formatted string
 * @c: The character to format
 */
void format_non_printable_char(char *buffer, char c)
{
    static const char *hex_digits = "0123456789ABCDEF";

    buffer[0] = '\\';
    buffer[1] = 'x';
    buffer[2] = hex_digits[(c >> 4) & 0xF];
    buffer[3] = hex_digits[c & 0xF];
}

/**
 * print_custom_string - Prints a string with
 * non-printable characters replaced
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 */
int print_custom_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    char buffer[5];
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127))
        {
            format_non_printable_char(buffer, str[i]);
            write(1, buffer, 4);
            count += 4;
        }
        else
        {
            write(1, &str[i], 1);
            count++;
        }
    }

    return (count);
}
