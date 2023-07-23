#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1

/**
 * struct form_spec - Structure
 * @specifier: Specifier as char
 * @fn: Function assigned to the char
 */
struct form_spec
{
	char specifier;
	int (*fn)(va_list, char *, int*, int, int);
};

/**
 * form_spect_t - Alias for the structure form_spec
 */
typedef struct form_spec form_spec_t;

/* Prototypes */

/* Our own printf function prototype */
int _printf(char *format, ...);

/* Function to print char and string */
int _putchar(char c);
int print_char(va_list ap, char *format, int *index,
int precision, int size);
int print_string(va_list ap, char *format, int *index,
int precision, int size);

/* Function to handle format specifier */
int _vprintf(char *buf, va_list ap, int *index,
int precision, int size);
int get_precision(char *format, int *k);
int get_size(const char *format, int *i);
char *itoa(int i);

/* Function to print numbers */
/* Integer numbers */
int print_number(va_list ap, char *format, int *index,
int precision, int size);
/* Double numbers */
int print_double(va_list ap, char *format, int *index,
int precision, int size);
/* Hexadecimal numbers */
int print_hexadecimal(va_list ap, char *format, int *index,
int precision, int size);
int print_hexa(va_list ap, char map_to[], char *buffer,
char flag_ch, int precision, int size);

/**
 * get_size - Function to get the size of the number
 * @format: String formatted
 * @i: The number
 *
 * Return: The size of the number
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

#endif
