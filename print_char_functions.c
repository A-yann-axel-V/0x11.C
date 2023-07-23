#include "main.h"

int print_char(va_list ap, char *format, int *index, int precision, int size)
{
    char value = va_arg(ap, int);
    UNUSED(index);
    UNUSED(format);
    UNUSED(precision);
    UNUSED(size);

    return (_putchar(value));
}

int print_string(va_list ap, char *format, int *index, int precision, int size)
{
    char *string = va_arg(ap, char*);
    int i = 0;
    UNUSED(format);
    UNUSED(precision);
    UNUSED(index);
    UNUSED(size);

    while (string[i])
    {
        _putchar(string[i]);
        i++;
    }

    return (i);
}