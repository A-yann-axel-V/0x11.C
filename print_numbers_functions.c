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
 * get_size - Calculate the minimum size for the printed value.
 * @value: The value for which to calculate the size.
 * @precision: The precision for printing (used for padding with leading zeros).
 *
 * Return: The minimum size for the printed value.
 */
int get_size(unsigned int value, int precision)
{
    int num_digits = (value == 0) ? 1 : 0, num_chars;
    unsigned int temp = value;

    /* Calculate the number of digits in the value in base 16 */
    while (temp != 0)
    {
        num_digits++;
        temp >>= 4;
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
 * @precision: The precision for printing (used for padding with leading zeros)
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
 * print_hexa - Wrapper function for printing hexadecimal numbers
 * @ap: va_list pointing to the hexadecimal value to print
 * @buffer: The buffer to store the formatted output
 * @map_to: Array to map hexadecimal digits
 * @format: The format string (not used for hexadecimal numbers)
 * @flag_ch: The flag character to be used (not used for hexadecimal numbers)
 * @precision: The precision for printing (used for padding with leading zeros)
 * @size: The minimum size for the printed value
 *
 * Return: The length of the output
 */
int print_hexa(va_list ap, char *format, int *index, int precision, int size)
{
	unsigned int value = va_arg(ap, unsigned int);
	int Vcase = (format[*index] == 'X') ? 0 : 1;

    UNUSED(size);

    return (print_hexa_value(value, precision, Vcase));
}

/**
 * print_hexa_value - Function to print hexadecimal numbers
 * @value: The hexadecimal value to print
 * @precision: The precision for printing (used for padding with leading zeros)
 * @flag_ch: The flag character to be used (not used for hexadecimal numbers)
 *
 * Return: The length of the output
 */
int print_hexa_value(unsigned int value, int precision, int isUpper)
{
    char hex_digit;
	int printed = 0, i, shift, rem, precision_zeros;
    int total_num_chars = get_size(value, precision);

    /** Print 0x at the start **
     * printed += _putchar('0');
     * printed += _putchar('x');
    */

    if (value == 0)
        printed += _putchar('0');
    else
    {
        precision_zeros = (precision > total_num_chars) ?
                            (precision - total_num_chars) : 0;

        for (i = 0; i < precision_zeros; i++)
            printed += _putchar('0');

        shift = (total_num_chars - 1) * 4;
        for (i = total_num_chars - 1; i >= 0; i--)
        {
            rem = (value >> shift) & 0xF;
            hex_digit = (rem < 10) ? ('0' + rem) :
                        (isUpper == 0 ? 'A' + rem - 10 : 'a' + rem - 10);
            printed += _putchar(hex_digit);
            shift -= 4;
        }
    }

    return (printed);
}

/**
 * get_long_size - Calculate the minimum size for the printed value.
 * @value: The value for which to calculate the size.
 * @precision: The precision for printing (used for padding with leading zeros).
 *
 * Return: The minimum size for the printed value.
 */
int get_long_size(unsigned long value, int precision)
{
    int num_digits = (value == 0) ? 1 : 0, num_chars;
    unsigned long temp = value;

    // Calculate the number of digits in the value (in base 10)
    while (temp != 0)
    {
        num_digits++;
        temp /= 10;
    }

    // Calculate the total number of characters needed for the output
    num_chars = (precision > num_digits) ? precision : num_digits;

    return (num_chars);
}

/**
 * print_unsigned - Print an unsigned number in either decimal or hexadecimal format.
 * @ap: The va_list containing the unsigned number argument.
 * @precision: The minimum number of characters to be printed.
 * @size: The minimum size for the printed value
 * @format: The format string (not used for hexadecimal numbers)
 * @index: The index of the current char
 *
 * Return: The total number of characters printed.
 */
int print_unsigned(va_list ap, char *format, int *index, int precision, int size)
{
    unsigned long num = va_arg(ap, unsigned long);
    char *buffer;
    int i;

    UNUSED(format);
    UNUSED(index);

    size = get_long_size(num, precision);
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    buffer[size] = '\0';

    // Convert the number to a string in decimal format.
    i = size - 1;
    while (i >= 0 && num != 0)
    {
        buffer[i] = '0' + (num % 10);
        num /= 10;
        i--;
    }

    // Print the number.
    while (*buffer)
	{
		_putchar(*buffer);
		buffer++;
	}

    return (size);
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
int print_octal_value(va_list ap, char *format, int *index, int precision, int size)
{
    unsigned long num = va_arg(ap, unsigned long);
    char *buffer;
    int i;

    UNUSED(format);
    UNUSED(index);

    size = get_long_size(num, precision);
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    buffer[size + 1] = '\0';

    // Convert the number to a string in octal format.
    i = size;
    while (i >= 0 && num >= 0)
    {
        buffer[i] = '0' + (num & 7);
        num >>= 3;
        i--;
    }

    while (*buffer)
	{
		_putchar(*buffer);
		buffer++;
	}

    return (size);
}
