#include "main.h"

/**
 * _printf - used to print output on the screen.
 * Works as `printf` C function
 *
 * @format: string to print
 *
 * Return: Length of output
*/
int _printf(char *format, ...)
{
	va_list args;
	int k = 0, printed = 0, precision = 0, size = 0;

	va_start(args, format);
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
			printed += _vprintf(format, args, &k, precision, size);
		}
		else
			printed += _putchar(format[k]);
		k++;
	}
	va_end(args);

	return (printed);
}
