#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */


int _reverse(va_list types, char buffer[],
int f, int w, int p, int s)
{

char *str;
int i;
int count = 0;

UNUSED(buffer);
UNUSED(f);
UNUSED(w);
UNUSED(s);


str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(p);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
return (count);
}
