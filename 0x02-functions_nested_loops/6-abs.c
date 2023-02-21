#include <stdlib.h>
#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 * @c: The number to compute.
 *
 * Return: The absolute value of the input integer or zero.
 */

int _abs(int c)
{
    if (c == 0)
    {
        return 0;
    }
    else if (c < 0)
    {
        int abs_val = c * -1;
        return abs_val;
    }
    else
    {
        return c;
    }
}
