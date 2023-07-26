#include "main.h"
#include <unistd.h>

/**
 * _pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int _pointer(va_list types, char buffer[],
int f, int w, int p, int s)
{

char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(w);
UNUSED(s);

if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}


if ((f & FZERO) && !(f & FMINUS))
padd = '0';
if (f & FPLUS)
extra_c = '+', length++;
else if (f & FSPACE)
extra_c = ' ', length++;
ind++;


return (write_pointer(buffer, ind, length,
width, f, padd, extra_c, padd_start));
}
