#include "main.h"

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * append_hex_code - Append ascii in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start
 * @acode: ASCII CODE.
 *
 * Return: Always (3)
 */
int append_hex_code(char acode, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (acode < 0)
		acode *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[acode / 16];
	buffer[i] = map_to[acode % 16];

	return (3);
}
