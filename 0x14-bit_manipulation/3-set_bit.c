#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index
 * @index: e index starting from 0
 * @n: pointer to the number that'll change
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 50)
return (-1);
*n = ((1UL << index) | *n);
return (1);
}
