#include "main.h"

/**
 * print_reverse - Prints reverse string.
 * @ap: List of arguments
 * @format: Buffer array to handle print
 * @index: The index of the current char
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list ap, const char *format, int *index, int precision,
					int size)
{
	char *str = va_arg(ap, char *);
	int k, printed = 0;

	UNUSED(format);
	UNUSED(index);
	UNUSED(size);
	UNUSED(precision);

	if (str == NULL)
	{
		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
	;

	for (k = k - 1; k >= 0; k--)
		printed += _putchar(str[k]);

	return (printed);
}
