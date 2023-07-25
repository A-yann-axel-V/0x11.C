#include "main.h"

/**
 * _printf - used to print output on the screen.
 * Works as `printf` C function
 *
 * @format: string to print
 *
 * Return: Length of output
*/
int _printf(const char *format, ...)
{
	va_list args;
	int k = 0, printed = 0, precision = 0, size = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[k] != '\0')
	{
		if (format[k] == '%')
		{
			print_buffer(buffer, &buff_ind);
			k++;
			if (format[k] == '.')
			{
				k++;
				precision = get_precision(format, &k);
			}
			if (format[k] == '%')
				printed += write(1, "%%", 1);
			else
				printed += _vprintf(format, args, &k, precision, size);
		}
		else
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed++;
		}
		k++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed);
}
