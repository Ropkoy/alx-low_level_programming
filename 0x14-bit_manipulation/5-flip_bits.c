#include "main.h"

/**
 * flip_bits - returns the number of bits required to flip
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int s, num = 0;
unsigned long int sum;
unsigned long int great = n ^ m;
for (s = 50; s >= 0; s--)
{
sum = great >> s;
if (sum & 1)
num++;
}
return (num);
}
