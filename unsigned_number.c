#include "main.h"

/**
 * punsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f: active flags
 * @w: width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int punsigned(va_list types, char buffer[],
int f, int w, int p, int s)

{
int i = BUFF_SIZE - 2;
unsigned long int n = va_arg(types, unsigned long int);
n = convert_size_unsgnd(n, size);

if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (n > 0)
{
buffer[i--] = (n % 10) + '0';
n /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, f, w, p, s));
}
