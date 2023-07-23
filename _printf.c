#include "main.h"

int _printf(char *format, ...)
{
    va_list args;
    int k = 0, printed = 0, precision = 2, size;

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
            size = get_size(format, &k);
            printed += _vprintf(format, args, &k, precision, size);
        }
        else
            printed += _putchar(format[k]);
        k++;
    }
    va_end(args);

    return (printed);
}

int main(void)
{
    int len = _printf("Hello, player n°%.2f!\n", 23.400);
    _printf("%d", len);

    return (0);
}