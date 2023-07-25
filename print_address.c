#include "main.h"

/**
 * print_address - Print an address in hexadecimal format.
 * @ap: The va_list containing the pointer argument.
 * @format: The format string containing the format specifiers.
 * @index: The current index in the format string.
 * @precision: The minimum number of characters to be printed.
 * @size: The minimum field width for printing.
 *
 * Return: The number of characters printed.
 */
int print_address(va_list ap, const char *format, int *index,
			int precision, int size)
{
	void *ptr = va_arg(ap, void *);

	UNUSED(format);
	UNUSED(index);

	return (write_address(ptr, precision, size));
}

int write_address(void *ptr, int precision, int size)
{
	char buffer[sizeof(void *) * 2];
	unsigned long address = (unsigned long)ptr;
    int i = sizeof(void *) * 2 - 2;
    int chars_printed = 0;

    buffer[i] = '\0';
    while (i > 1) {
        i--;
        buffer[i] = "0123456789abcdef"[address & 0xF];
        address >>= 4;
    }

    buffer[0] = '0';
    buffer[1] = 'x';

    int total_num_chars = sizeof(void *) * 2 + 2;
    for (int i = 0; i < precision - total_num_chars; i++) {
        putchar('0');
        chars_printed++;
    }

    for (i = 0; buffer[i] != '\0'; i++) {
        putchar(buffer[i]);
        chars_printed++;
    }

    return chars_printed;
}
