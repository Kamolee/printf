#include "main.h"
#include <unistd.h>


/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int ind, char buffer[],
int f, int w, int p, int s)

{
int l = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(s);

if ((f & FZERO) && !(f & FMINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (f & FPLUS)
extra_ch = '+';
else if (f & FSPACE)
extra_ch = ' ';
return (write_num(ind, buffer, f, w, p,
l, padd, extra_ch));
}
