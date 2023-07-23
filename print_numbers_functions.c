#include "main.h"


int get_precision(char *format, int *k)
{
    int precision = 0;

    while (format[*k] >= '0' && format[*k] <= '9')
    {
        precision = precision * 10 +(format[*k] - '0');
        *k += 1;
    }

    return (precision);
}

int print_number(va_list ap, char *format, int *index, int precision, int size)
{
    int k = 1, number_copy, value, printed = 0;
    int number = va_arg(ap, int);
    UNUSED(format);
    UNUSED(precision);
    UNUSED(index);
    UNUSED(size);

    if (number >= 0 && number < 10)
        return (_putchar(number + '0'));

    if (number < 0)
    {
        _putchar('-');
        number *= -1;
        printed++;
    }

    number_copy = number;
    while (number_copy / 10 != 0)
    {
        k *= 10;
        number_copy /= 10;
    }

    while (k != 0)
    {
        value = number / k;
        _putchar(value + '0');
        printed++;
        number %= k;
        k /= 10;
    }

    return (printed);
}

int print_double(va_list ap, char *format, int *index, int precision, int size)
{
    double float_number = va_arg(ap, double);
    int integer_part = (int)float_number, digit, printed = 0, n = 0;
    float frac_part = float_number - integer_part;
    char *value;
    UNUSED(format);
    UNUSED(index);
    UNUSED(size);

    value = itoa(integer_part);
    while (*value)
    {
        printed += _putchar(*value);
        value++;
    }
    printed += _putchar('.');
    while (n < precision)
    {
        frac_part *= 10;
        digit = (int)frac_part;
        frac_part -= digit;
        n++;
        printed += _putchar(digit + '0');
    }

    return (printed);
}

int print_hexadecimal(va_list ap, char *format, int *index, int precision, int size)
{
    UNUSED(index);
 	return (print_hexa(ap, "0123456789abcdef", format, 'x', precision, size));
}

int print_hexa(va_list ap, char map_to[], char *buffer, char flag_ch, int precision, int size)
{ 	 
 	// int i = BUFF_SIZE - 2; 
 	// unsigned long int num = va_arg(ap, unsigned long int); 
 	// unsigned long int init_num = num; 
 
 	// num = convert_size_unsgnd(num, size); 
 	// if (num == 0) 
 
 	//  	buffer[i--] = '0'; 
 
 	// buffer[BUFF_SIZE - 1] = '\0'; 
 	// while (num > 0) 
 	// { 
 	//  	buffer[i--] = map_to[num % 16]; 
 	//  	num /= 16; 
 
 	// } 
 	// if (flags & F_HASH && init_num != 0) 
 	// { 
 	//  	buffer[i--] = flag_ch; 
 	//  	buffer[i--] = '0'; 
 
 	// } 
 
 	// i++; 
    // return (write_unsgnd(0, i, buffer, flags, width, precision, size));

    return (_putchar(2 + '0'));
 
}
