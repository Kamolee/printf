#include "main.h"

/**
 * digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
