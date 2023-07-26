#include "main.h"


/**
 * Octal - Prints an unsigned number in octal notation
 * @types:  arguments
 * @buffer: Buffer array to handle print
 * @f: Calculates active flags
 * @w: width
 * @p: Precision
 * @s: Size
 * Return: Number of chars printed
 */

int Octal(va_list types, char buffer[],
int f, int w, int p, int s)

{

int i = BUFF_SIZE - 2;
unsigned long int n = va_arg(types, unsigned long int);
unsigned long int init_num = n;
UNUSED(w);
n = convert_size_unsgnd(n, s);


if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (n > 0)
{
buffer[i--] = (n % 8) + '0';
n /= 8;
}
if (f & FHASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, f, w, p, s));
}
