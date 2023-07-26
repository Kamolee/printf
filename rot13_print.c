#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @f: f
 * @w: width
 * @p: Precision specification
 * @s: Size
 * Return: Numbers of chars printed
 */

int _rot13string(va_list types, char buffer[],
int f, int w, int p, int s)
{

char x;
char *str;
unsigned int i;
unsigned int j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";


str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(f);
UNUSED(w);
UNUSED(p);
UNUSED(s);


if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
}
