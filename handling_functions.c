#include "main.h"

/**
 * itoa - Convert integer to char
 * @i: The integer to convert
 *
 * Return: Char *
 */
char *itoa(int i)
{
	char *ptr;
	int count = 0, n = i, x = 1, k;

	while (n != 0)
	{
		count++;
		n /= 10;
		x *= 10;
	}

	x /= 10;
	ptr = (char *)malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		exit(1);

	for (k = count - 1; k >= 0; k--)
	{
		if (i < 10)
			ptr[k] = i + '0';
		else
			ptr[k] = (i % x) + '0';
		i /= 10;
		x /= 10;
	}
	ptr[count] = '\0';
	return (ptr);
}

/**
 * _putchar - print a char
 * @c: The char to print
 *
 * Return: The length of the output
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _vprintf - replacing any format specifier in the same way as printf
 * @buf: The string formatted
 * @ap: va_list parameter
 * @index: The index of the current char
 * @precision: Number of integer after dot symbol
 * @size: The size of the number
 *
 * Return: The length of the output
 */
int _vprintf(const char *buf, va_list ap, int *index, int precision, int size)
{
	int i = 0, printed;
	form_spec_t f_spec[] = {
		{ 'c', print_char }, { 'd', print_number }, { 'i', print_number },
		{ 'f', print_double }, { 's', print_string }, { 'x', print_hexa },
		{ 'X', print_hexa }, { 'u', print_unsigned }, { 'p', print_address },
		{ 'o', print_octal_value }, { '\0', NULL }
	};

	while (f_spec[i].specifier != '\0')
	{
		if (f_spec[i].specifier == buf[*index])
			return (f_spec[i].fn(ap, buf, index, precision, size));
		i++;
	}

	printed = _putchar(buf[--*index]);
	*index += 1;
	printed += _putchar(buf[*index]);
	return (printed);
}

/**
 * get_precision - Get Number of integer after dot symbol
 * @format: String formatted
 * @k: Index of the current char in the string
 *
 * Return: The number of integer
 */
int get_precision(const char *format, int *k)
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
 * @precision: The precision for printing (used for padding with leading zeros)
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
