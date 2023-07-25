#include "main.h"

/**
 * _putchar - print a char
 * @c: The char to print
 *
 * Return: The length of the output
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}