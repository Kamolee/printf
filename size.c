#include "main.h"
/**
 * size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */

int size(const char *format, int *i)
{
int c = *i + 1;
int s = 0;
if (format[c] == 'l')
s = SLONG;
else if (format[c] == 'h')
s = SSHORT;
if (s == 0)
*i = c - 1;
else
*i = c;
return (s);
}
