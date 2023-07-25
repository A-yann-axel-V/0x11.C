#include "main.h"

/**
 * print_hexa - Wrapper function for printing hexadecimal numbers
 * @ap: va_list pointing to the hexadecimal value to print
 * @format: The format string (not used for hexadecimal numbers)
 * @index: The index of the current char
 * @precision: The precision for printing (used for padding with leading zeros)
 * @size: The minimum size for the printed value
 *
 * Return: The length of the output
 */
int print_hexa(va_list ap, const char *format, int *index, int precision,
int size)
{
	unsigned int value = va_arg(ap, unsigned int);
	int Vcase = (format[*index] == 'X') ? 0 : 1;

	return (print_hexa_value(value, precision, Vcase, size));
}

/**
 * print_hexa_value - Function to print hexadecimal numbers
 * @value: The hexadecimal value to print
 * @precision: The precision for printing (used for padding with leading zeros)
 * @isUpper: Indicates whether the hexadecimal value
 * should be uppercase or lowercase
 * @size: The minimum size for the printed value
 *
 * Return: The length of the output
 */
int print_hexa_value(unsigned int num, int precision, int isUpper, int size)
{
	char buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 2;
	char *map_to = (isUpper == 0 ? "0123456789ABCDEF" : "0123456789abcdef");

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	i++;

	return (write_unsgnd(i, buffer, precision, size));
}

/**
 * get_long_size - Calculate the minimum size for the printed value.
 * @value: The value for which to calculate the size.
 * @precision: The precision for printing (used for padding with leading zeros)
 *
 * Return: The minimum size for the printed value.
 */
int get_long_size(unsigned long value, int precision)
{
	int num_digits = (value == 0) ? 1 : 0, num_chars;
	unsigned long temp = value;

	/* Calculate the number of digits in the value (in base 10) */
	while (temp != 0)
	{
		num_digits++;
		temp /= 10;
	}

	/* Calculate the total number of characters needed for the output */
	num_chars = (precision > num_digits) ? precision : num_digits;

	return (num_chars);
}

/**
 * print_unsigned - Print an unsigned number in either decimal
 * or hexadecimal format.
 * @ap: The va_list containing the unsigned number argument.
 * @precision: The minimum number of characters to be printed.
 * @size: The minimum size for the printed value
 * @format: The format string (not used for hexadecimal numbers)
 * @index: The index of the current char
 *
 * Return: The total number of characters printed.
 */
int print_unsigned(va_list ap, const char *format, int *index,
			int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	char buffer[BUFF_SIZE];

	UNUSED(format);
	UNUSED(index);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(i, buffer, precision, size));
}

/**
 * print_octal_value - Print the octal value of an unsigned number.
 * @ap: The va_list containing the unsigned number argument.
 * @precision: The minimum number of characters to be printed.
 * @size: The minimum size for the printed value
 * @format: The format string (not used for hexadecimal numbers)
 * @index: The index of the current char
 *
 * Return: The total number of characters printed.
 */
int print_octal_value(va_list ap, const char *format, int *index,
			int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	char buffer[BUFF_SIZE];

	UNUSED(format);
	UNUSED(index);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	i++;

	return (write_unsgnd(i, buffer, precision, size));
}
