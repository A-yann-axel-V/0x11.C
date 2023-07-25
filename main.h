#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
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
	int (*fn)(va_list, const char *, int*, int, int);
};

/**
 * form_spect_t - Alias for the structure form_spec
 */
typedef struct form_spec form_spec_t;

/* Prototypes */

/* Our own printf function prototype */
int _printf(const char *format, ...);

/* Utils */
long int convert_size_unsgnd(unsigned long int num, int size);

/* Functions to print char and string */
int _putchar(char c);
void print_buffer(char buffer[], int *buff_ind);
int print_char(va_list ap, const char *format, int *index,
int precision, int size);
int print_string(va_list ap, const char *format, int *index,
int precision, int size);

/* Functions to handle format specifier */
int _vprintf(const char *buf, va_list ap, int *index,
				int precision, int size);
int get_precision(const char *format, int *k);
int get_size(unsigned int value, int precision);
char *itoa(int i);
int write_unsgnd(int ind, char *buffer, int precision, int size);

/* Functions to print numbers */
/* Integer numbers */
int print_number(va_list ap, const char *format, int *index,
					int precision, int size);
/* Double numbers */
int print_double(va_list ap, const char *format, int *index,
					int precision, int size);
/* Hexadecimal numbers */
int print_hexa_value(unsigned int num, int precision, int isUpper, int size);
int print_hexa(va_list ap, const char *format, int *index, int precision,
				int size);
/* Unsigned numbers */
int print_unsigned(va_list ap, const char *format, int *index, int precision,
					int size);
/* Octal numbers */
int print_octal_value(va_list ap, const char *format, int *index,
						int precision, int size);
/* Binary values */
int print_binary(va_list ap, int precision, int size);


/* Functions to print address */
int print_address(va_list ap, const char *format, int *index,
					int precision, int size);
int write_address(void *ptr, int precision, int size);

#endif
