#include "./functions.h"

int main(void)
{
    char *strng = "Bonjour, j'ai %d ans";
    int value = 12;

    // _printf(strng, 12);
    // _printf("Mon frére %s a %d ans\n", "Yann", 4);
    _printf("%s", itos(value));

    return (0);
}