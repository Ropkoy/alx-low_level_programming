#include "main.h"

/**
 * clear_bit - set value ofa bit to 0 at a given index
 * @index: index starting from 0
 * @n: pointer to the number that'll change
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 50)
return (-1);
*n = (~(1UL << index) & *n);
return (1);
}
