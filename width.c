#include "main.h"

/**
 * width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int width(const char *format, int *i, va_list list)
{
int c;
int w = 0;
for (c = *i + 1; format[c] != '\0'; c++)
{
if (digit(format[c]))
{
w *= 10;
w += format[c] - '0';
}
else if (format[c] == '*')
{
c++;
w = va_arg(list, int);
break;
}
else
break;
}
*i = c - 1;
return (w);
}
