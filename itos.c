#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * itos - convert an int to a string
 * @i: the int to convert
 * 
 * Return: Pointer to the converted string
*/
char *itos(int i)
{
    char *ptr;
    int count = 0, n = i, x = 1;

    while (n != 0)
    {
        count++;
        n /= 10;
        x *= 10;
    }

    x /= 10;

    ptr = (char *)malloc((count + 1) * sizeof(char));
    if (ptr == NULL)
        exit(1);

    for (int k = count - 1; k >= 0; k--)
    {
        if (i < 10)
            ptr[k] = i + '0';
        else
            ptr[k] = (i % x) + '0';
        i /= 10;
        x /= 10;
    }
    ptr[count] = '\0';

    return (ptr);
}