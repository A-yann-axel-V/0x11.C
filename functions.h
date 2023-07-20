#ifndef FUN_H
#define FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * _putchar - print a character
 * @c: the character to print
 * 
 * Return: nothing
*/
char _putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

/**
 * print_n - print an integer
 * @n: the number to print
 * 
 * Return: nothing
*/
void print_n(int n)
{
    int k = 1, x, value;

    if (n >= 0 && n < 10)
    {
        _putchar(n + '0');
        return;
    }

    if (n < 0) {
        _putchar('-');
        n *= -1;
    }

    x = n;

    while (x / 10 != 0)
    {
        k *= 10;
        x = x / 10;
    }

    while (k != 0)
    {
        value = n / k;
        _putchar(value + '0');
        n %= k;
        k /= 10;
    }
}

/**
 * print_h - convert an int to hex and print the hex string
 * @h: int to print
 * 
 * Return: nothing
*/
void print_h(int h)
{

}


/**
 * _printf - printf a string as the `printf` function
 * @strng: string to print
 * 
 * Return: nothing
*/
char * _printf(char *strng, ...)
{
    va_list args; // Déclaratiion de la variable qui récuperera les arguments
    va_start(args, strng); // Initialisation de la variable
    char *error;


    // Empty string
    if (strlen(strng) == 0)
    {
        strcpy(error, "Error. Cannot print a NULL string.\n");
        for (unsigned int i = 0; i < strlen(error); i++)
            _putchar(error[i]);
        return (NULL);
    }

    // String not empty
    while (*strng)
    {
        if (*strng == '%') // Checking for a format specifier
        {
            strng++;

            if (*strng == 'd')
            {
                int value = va_arg(args, int);
                print_n(value);
            }
            else if (*strng == 'c')
            {
                int value = va_arg(args, int);
                _putchar(value);
            }
            else if (*strng == 's')
            {
                char *value = va_arg(args, char*);
                for (unsigned int i = 0; i < strlen(value); i++)
                    _putchar(value[i]);
            }
            else if (*strng == 'x')
            {
                int value = va_arg(args, int);
                print_h(value);
            }
        }
        else
            _putchar(*strng);

        strng++;
    }

    return (0);
}

#endif
