#include "main.h"

int print_binary(va_list ap, int precision, int size)
{
    unsigned int n, m, i, sum;
	unsigned int a[32];
	int printed;
    char z;

	UNUSED(precision);
	UNUSED(size);

	n = va_arg(ap, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, printed = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			z = '0' + a[i];
			printed += _putchar(z);
		}
	}
	return (printed);
}
