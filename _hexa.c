#include "main.h"

/**
 * _hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int p_hexadecimal(va_list types, char buffer[],
int f, int w, int p, int s)

{
return (print_hexa(types, "0123456789abcdef", buffer,
f, 'x', w, p, s));
}
