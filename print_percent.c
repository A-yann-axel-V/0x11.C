#include "main.h"

/**
 * print_percent - Write percent symbol
 * @ap: List of arguments
 * @format: Buffer array to handle print
 * @index: The index of the current char
 * @precision: Precision
 * @size: Size specifier
 * Return: 1
 */
int print_percent(va_list ap, const char *format, int *index,
			int precision, int size)
{
	UNUSED(ap);
	UNUSED(precision);
	UNUSED(format);
	UNUSED(index);
	UNUSED(size);

	return (write(1, "%%", 1));
}
