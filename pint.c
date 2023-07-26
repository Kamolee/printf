#include "main.h"
#include <unistd.h>
#include "main.h"

/**
 * pchar - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: Width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int pchar(va_list types, char buffer[],
int f, int w, int p, int s)

{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, f, w, p, s));
}
