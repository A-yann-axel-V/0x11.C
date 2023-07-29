# 0x11.C - Printf project
Prototype: int _printf(const char *format, ...);

# Authorized functions and macros
    • write (man 2 write)
    • malloc (man 3 malloc)
    • free (man 3 free)
    • va_start (man 3 va_start)
    • va_end (man 3 va_end)
    • va_copy (man 3 va_copy)
    • va_arg (man 3 va_arg)

Use this to compile: `$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`

You can test using the main.c file

# Tasks
0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
*mandatory*
Write a function that produces output according to a format.
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
**NOTE**: 99%, One check failed

1. Education is when you read the fine print. Experience is what you get if you don't
*mandatory*
Handle the following conversion specifiers:
d
i
**NOTE**: 100%, All done

# Collab:
Maxwell Arthur & Adjumany Yann
**FYI**: We got 153%
