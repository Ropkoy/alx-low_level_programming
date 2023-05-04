#include "main.h"

/**
 * get_endianness - checks for the endianness
 * Return: 0 for big endian & 1 for small endian
 */

int get_endianness(void)
{
unsigned int s = 1;
char *m = (char *) &s;
return (*m);
}
