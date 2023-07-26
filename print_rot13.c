#include "main.h"

/**
 * print_rot13string - Print a string in rot13.
 * @ap: Lista of arguments
 * @format: Buffer array to handle print
 * @index: The index of the current char
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13(va_list ap, const char *format, int *index, int precision,
					int size)
{
	char *str = va_arg(ap, char *);
	unsigned int i, j;
	int printed = 0;
	char n_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot_alpha[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	UNUSED(format);
	UNUSED(index);
	UNUSED(size);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; n_alpha[j]; j++)
		{
			if (n_alpha[j] == str[i])
			{
				printed += _putchar(rot_alpha[j]);
				break;
			}
		}
		if (!n_alpha[j])
		{
			printed += _putchar(str[i]);
		}
	}

	return (printed);
}
