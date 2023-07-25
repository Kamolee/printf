#include <stdarg.h>
/**
 * _percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int _percent(va_list types, char buffer[],
int f, int w, int p, int s)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(f);
UNUSED(w);
UNUSED(p);
UNUSED(s);
return (write(1, "%%", 1));
}
