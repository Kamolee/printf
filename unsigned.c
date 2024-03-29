#include "main.h"
#include <unistd.h>

/**
 * write_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */

int write_unsigned(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)
{

int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0); /* printf(".0d", 0)  no char is printed */
if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}

if ((flags & FZERO) && !(flags & FMINUS))
padd = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & FMINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}
else /* Asign extra char to left of padding [padd>buffer]*/
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
