#include <stdio.h>

void _putchar(char c);

int main()
{
    char str[] = "Hello, world!";
    char accept[] = "aeiouy";

    // Search for first vowel in str
    char *result = _strpbrk(str, accept);

    // Print result
    if (result == NULL) {
        _putchar('N');
        _putchar('o');
        _putchar(' ');
        _putchar('v');
        _putchar('o');
        _putchar('w');
        _putchar('e');
        _putchar('l');
        _putchar('s');
        _putchar(' ');
        _putchar('f');
        _putchar('o');
        _putchar('u');
        _putchar('n');
        _putchar('d');
        _putchar('\n');
    } else {
        _putchar('F');
        _putchar('i');
        _putchar('r');
        _putchar('s');
        _putchar('t');
        _putchar(' ');
        _putchar('v');
        _putchar('o');
        _putchar('w');
        _putchar('e');
        _putchar('l');
        _putchar(':');
        _putchar(' ');
        _putchar(*result);
        _putchar('\n');
    }

    return 0;
}
