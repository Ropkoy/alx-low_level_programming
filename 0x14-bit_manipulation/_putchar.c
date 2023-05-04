#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes teh character c to stdout
 * @c: Character to print
 *
 * Return: 1 for success or  -1 for error, and error no is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
