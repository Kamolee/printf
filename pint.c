#include "main.h"
#include <unistd.h>

/**
 * _int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int _int(va_list types, char buffer[],
int f, int w, int p, int s)
{

int j = BUFF_SIZE - 2;
int s_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, s);
if (n == 0)
buffer[j--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
s_negative = 1;
}
while (num > 0)
{
buffer[j--] = (num % 10) + '0';
num /= 10;
}
j++;
return (write_number(s_negative, j, buffer, f, w, p, s));
}
