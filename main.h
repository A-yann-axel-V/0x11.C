#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <string.h>

#define UNUSED(x) (void)(x)

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
int get_size(unsigned int value, int precision);
char *itoa(int i);

/* Function to print numbers */
/* Integer numbers */
int print_number(va_list ap, char *format, int *index,
					int precision, int size);
/* Double numbers */
int print_double(va_list ap, char *format, int *index,
					int precision, int size);
/* Hexadecimal numbers */
int print_hexa_value(unsigned int value, int precision, int isUpper);
int print_hexa(va_list ap, char *format, int *index, int precision,
				int size);
/* Unsigned numbers */
int print_unsigned(va_list ap, char *format, int *index, int precision,
					int size);

#endif
