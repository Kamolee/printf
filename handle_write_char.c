#include "main.h"
#include <unistd.h>

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags.
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
int f, int w, int p, int s)

{
int i = 0;
char padd = ' ';
UNUSED(p);
UNUSED(s);
if (f & FZERO)
padd = '0';
buffer[i++] = c;
buffer[i] = '\0';
if (w > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < w - 1; i++)
buffer[BUFF_SIZE - i - 2] = padd;
if (f & FMINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - i - 1], w - 1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], w - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
