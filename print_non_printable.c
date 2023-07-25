#include "main.h"

int print_non_printable(va_list ap, const char *format, int *index, int precision,
				int size)
{
	int i = 0, start = 0;
	char *str = va_arg(ap, char *), buffer[BUFF_SIZE];

	UNUSED(precision);
	UNUSED(size);
    UNUSED(format);
    UNUSED(index);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			buffer[i + start] = str[i];
		else
			start += append_hex_code(str[i], buffer, i + start);
		i++;
	}

	buffer[i + start] = '\0';

	return (write(1, buffer, i + start));
}
