#include "main.h"

/**
 * print_number - Print integer number
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: The precision for printing (used for padding with leading zeros)
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_number(va_list ap, const char *format, int *index,
int precision, int size)
{
	int k = 1, value, printed = 0, len = BUFF_SIZE - *index - 1;
	long int number = va_arg(ap, long int);
	unsigned long int number_copy;

	UNUSED(format);
	UNUSED(index);
	size = get_size(number, precision);
	number = convert_size_number(number, size);
	if (number >= 0 && number < 10)
		return (_putchar(number + '0'));

	if (number < 0)
		printed += _putchar('-'), number *= -1;

	number_copy = number;
	while (number_copy / 10 != 0)
	{
		k *= 10;
		number_copy /= 10;
	}

	while (precision > len)
		printed += _putchar('0'), len++;
	while (k != 0)
	{
		value = number / k;
		printed += _putchar(value + '0');
		number %= k;
		k /= 10;
	}
	return (printed);
}

/**
 * print_double - Print double number
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: The precision for printing (used for padding with leading zeros)
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_double(va_list ap, const char *format, int *index,
int precision, int size)
{
	double float_number = va_arg(ap, double);
	int integer_part = (int)float_number, digit, printed = 0, n = 0;
	float frac_part = float_number - integer_part;
	char *value;

	UNUSED(format);
	UNUSED(index);
	UNUSED(size);

	value = itoa(integer_part);
	while (*value)
	{
		printed += _putchar(*value);
		value++;
	}
	printed += _putchar('.');
	while (n < precision)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		frac_part -= digit;
		n++;
		printed += _putchar(digit + '0');
	}

	return (printed);
}
