#include "main.h"

/**
 * get_precision - Get Number of integer after dot symbol
 * @format: String formatted
 * @k: Index of the current char in the string
 *
 * Return: The number of integer
 */
int get_precision(char *format, int *k)
{
	int precision = 0;

	while (format[*k] >= '0' && format[*k] <= '9')
	{
		precision = precision * 10 + (format[*k] - '0');
		*k += 1;
	}

	return (precision);
}

/**
 * print_number - Print integer number
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_number(va_list ap, char *format, int *index, int precision, int size)
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
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_double(va_list ap, char *format, int *index, int precision, int size)
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

/**
 * print_hexadecimal - Print hexadecimal number
 * @ap: va_list parameter
 * @format: The string formatted
 * @index: The index of the current char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_hexadecimal(va_list ap, char *format, int *index,
			int precision, int size)
{
	UNUSED(index);
	return (print_hexa(ap, "0123456789abcdef", format, 'x',
		precision, size));
}

/**
 * print_char - Print one character
 * @ap: va_list parameter
 * @format: The string formatted
 * @map_to: Array of letters used by the function
 * @flag_ch: Parameter as char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int print_hexa(va_list ap, char map_to[], char *format, char flag_ch,
		int precision, int size)
{
	/**
	* int i = BUFF_SIZE - 2;
	* unsigned long int num = va_arg(ap, unsigned long int);
	* unsigned long int init_num = num;
	*
	* num = convert_size_unsgnd(num, size);
	* if (num == 0)
	*	buffer[i--] = '0';
	*
	* buffer[BUFF_SIZE - 1] = '\0';
	* while (num > 0)
	* {
	*	buffer[i--] = map_to[num % 16];
	*	num /= 16;
	* }
	*
	* if (flags & F_HASH && init_num != 0)
	* {
	*	buffer[i--] = flag_ch;
	*	buffer[i--] = '0';
	* }
	*
	* i++;
	* return (write_unsgnd(0, i, buffer, flags, width, precision, size));
	*/
	return (_putchar(2 + '0'));
}
