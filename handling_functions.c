#include "main.h"

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

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _vprintf(char *buf, va_list ap, int *index, int precision, int size)
{
    int i = 0;
    form_spec_t f_spec[] = {
        { 'c', print_char }, { 'd', print_number }, { 'i', print_number },
        { 'f', print_double }, { 's', print_string }, { 'x', print_hexadecimal },
        { '\0', NULL }
    };

    while (f_spec[i].specifier != '\0')
    {
        if (f_spec[i].specifier == buf[*index])
            return (f_spec[i].fn(ap, buf, index, precision, size));
        i++;
    }

    return (-1);
}
