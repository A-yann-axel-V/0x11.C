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
	int len = 0;

	UNUSED(format);
	UNUSED(precision);
	UNUSED(index);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[len])
		len++;

	return (write(1, string, len));
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
