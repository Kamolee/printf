#include <stdarg.h>
/**
 * pbinary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of characters printed.
 */

int pbinary(va_list types, char buffer[],
int f, int w, int p, int s)
{

unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(f);
UNUSED(w);
UNUSED(p);
UNUSED(s);

n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
