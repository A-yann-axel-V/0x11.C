#include "main.h"

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
	int k = 1, number_copy, value, printed = 0;
	int number = va_arg(ap, int);

	UNUSED(format);
	UNUSED(precision);
	UNUSED(index);
	UNUSED(size);

	if (number >= 0 && number < 10)
		return (_putchar(number + '0'));

	if (number < 0)
	{
		_putchar('-');
		number *= -1;
		printed++;
	}

	number_copy = number;
	while (number_copy / 10 != 0)
	{
		k *= 10;
		number_copy /= 10;
	}

	while (k != 0)
	{
		value = number / k;
		_putchar(value + '0');
		printed++;
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
