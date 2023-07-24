#include "main.h"

/**
 * print_char - Print one character
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_char(va_list ap, const char *format, int *index,
int precision, int size)
{
	char value = va_arg(ap, int);

	UNUSED(index);
	UNUSED(format);
	UNUSED(precision);
	UNUSED(size);

	return (_putchar(value));
}

/**
 * print_string - Print one character
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_string(va_list ap, const char *format, int *index,
int precision, int size)
{
	char *string = va_arg(ap, char*);
	int i = 0;

	UNUSED(format);
	UNUSED(precision);
	UNUSED(index);
	UNUSED(size);

	if (string == NULL)
		string = "(null)";
	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}

	return (i);
}
