#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"

/**
* pstring - Prints a string
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @f:  Calculates active flags
* @w: get width.
* @p: Precision specification
* @s: Size specifier
* Return: Number of chars printed
*/

int pstring(va_list types, char buffer[],
int f, int w, int p, int s)

{
int length = 0;
int i;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(f);
UNUSED(w);
UNUSED(p);
UNUSED(s);
if (str == NULL)
{
str = "(null)";
if (p >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (p >= 0 && p < length)
length = p;
if (w > length)
{
if (f & FMINUS)
{
write(1, &str[0], length);
for (i = w - length; i > 0; i--)
write(1, " ", 1);
return (w);
}
else
{
for (i = w - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (w);
}
}
return (write(1, str, length));
}
