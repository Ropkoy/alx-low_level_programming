#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 *@@n: the num to be printed in the binary
 */

void print_binary(unsigned long int n)
{
int s, sum = 0;
unsigned long int num;
for (s = 63; s >= 0; s--)
{
num = n >> s;
if (num & 1)
{
_putchar('1');
sum++;
}
else if (sum)
_putchar('0');
}
if (!sum)
_putchar ('0');
}
