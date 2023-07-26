#include "main.h"

/**
 * print_address - Print an address in hexadecimal format.
 * @ap: The va_list containing the pointer argument.
 * @format: The format string containing the format specifiers.
 * @index: The current index in the format string.
 * @precision: The minimum number of characters to be printed.
 * @size: The minimum field width for printing.
 *
 * Return: The number of characters printed.
 */
int print_address(va_list ap, const char *format, int *index,
			int precision, int size)
{
	void *ptr = va_arg(ap, void *);

	UNUSED(format);
	UNUSED(index);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	return (write_address(ptr, precision, size));
}

/**
 * write_address - function converts a memory address represented
 * by a void pointer (ptr) into a human-readable hexadecimal format
 * and prints it to the standard output. The function takes three
 * parameters: ptr, precision, and size.
 * @ptr: A void pointer pointing to the memory address
 * that needs to be printed.
 * @precision: An integer representing the minimum number of
 * characters to be printed.
 * If the hexadecimal representation of the address has fewer characters
 * than the specified precision, leading zeros will be added to meet the
 * precision requirement.
 * @size: An integer indicating the size of the data pointed to by ptr.
 * However, it is not used within the function.
 *
 * Return: Length of the output
 */
int write_address(void *ptr, int precision, int size)
{
	char buffer[sizeof(void *) * 2];
	unsigned long address = (unsigned long)ptr;
	int i = sizeof(void *) * 2 - 2;
	int chars_printed = 0, total_num_chars;

	UNUSED(size);
	buffer[i] = '\0';
	while (i > 1)
	{
		i--;
		buffer[i] = "0123456789abcdef"[address & 0xF];
		address >>= 4;
	}

	buffer[0] = '0';
	buffer[1] = 'x';

	total_num_chars = sizeof(void *) * 2 + 2;
	for (i = 0; i < precision - total_num_chars; i++)
		chars_printed += _putchar('0');

	for (i = 0; buffer[i] != '\0'; i++)
	;

	return (write(1, &buffer, i + chars_printed));
}
