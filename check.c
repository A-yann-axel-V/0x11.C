#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * check - Check the validity
 * @specifier: the format specifier
 * @a: the value
 * 
 * Return: true if the format specifier is valid else false
*/

bool check(char specifier,const void* a)
{
    /*
        We'll use this for checking
        if (!check(*strng, va_arg(args, void*)))
        {
            strcpy(error, "Error: Invalid type\n");
            for (unsigned int i = 0; i < strlen(error); i++)
                _putchar(error[i]);
            return (NULL);
        }
    */
    if (specifier == 'd')
        return (a != NULL && sizeof(*((int*)a)) == sizeof(int));
    if (specifier == 'c')
        return (a != NULL && sizeof(*((char*)a)) == sizeof(char));
    if (specifier == 's')
        return (a != NULL && strcmp(*((char**)a), "") != 0);

    return (false);
}