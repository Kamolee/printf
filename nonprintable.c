#include "main.h"
#include <unistd.h>


/**
* _non_printable - Prints ascii codes in hexa of non printable chars
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @f: flags
* @w: width
* @p: Precision
* @s: Size
* Return: Number of chars printed
*/

int _non_printable(va_list types, char buffer[],
int f, int w, int p, int s)

{
int j = 0;
int offset = 0;
char *str = va_arg(types, char *);

UNUSED(f);
UNUSED(w);
UNUSED(p);
UNUSED(s);

if (str == NULL)
return (write(1, "(null)", 6));
while (str[j] != '\0')
{
if (_printable(str[j]))
buffer[j + offset] = str[j];
else
offset += append_hexa_code(str[j], buffer, j + offset);
j++;
}
buffer[j + offset] = '\0';
return (write(1, buffer, j + offset));
}
