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

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[k] != '\0')
	{
		if (format[k] == '%')
		{
			k++;
			if (format[k] == '.')
			{
				k++;
				precision = get_precision(format, &k);
			}
			if (format[k] == '%')
				printed += _putchar('%');
			else
			{
				_vprintf(format, args, &k, precision, size);
				printed++;
			}
		}
		else
			printed += _putchar(format[k]);
		k++;
	}
	va_end(args);

	return (printed);
}
