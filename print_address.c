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
int print_address(va_list ap, char *format, int *index,
			int precision, int size)
{
	uintptr_t ptr = (uintptr_t)va_arg(ap, void *);
	uintptr_t temp = ptr;
	int num_digits = 0, chars_printed = 0, total_chars, i, padding, digit;
	char *buffer;

	UNUSED(format);
	UNUSED(index);
	buffer = malloc(sizeof(char) * (num_digits + 1));
	if (buffer == NULL)
		return (-1);

	chars_printed += _putchar('0');
	chars_printed += _putchar('x');

	while (temp > 0)
	{
		temp /= 16;
		num_digits++;
	}

	if (ptr == 0)
	{
		_putchar('0');
		return (1);
	}
	buffer[num_digits] = '\0';
	for (i = num_digits - 1; i >= 0; i--)
	{
		digit = ptr % 16;
		buffer[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		ptr /= 16;
	}

	total_chars = (precision > num_digits) ? precision : num_digits;
	for (i = 0; i < num_digits; i++)
		chars_printed += _putchar(buffer[i]);

	return (chars_printed);
}
