#include "main.h"
#include <unistd.h>
#include <stdarg.h>


/**
 * _printf - Printf function
 * @format: format
 * Return: Printed characters
 */


int _printf(const char *format, ...)
{
int j;
int print = 0;
int p_chars = 0;
int index = 0;
int f;
int w;
int p;
int s;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);
for (j = 0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
buffer[index++] = format[j];
if (index == BUFF_SIZE)
print_buff(buffer, &index);

p_chars++;
}
else
{
print_buff(buffer, &index);
f = flags(format, &j);
w = width(format, &j, list);
p = precision(format, &j, list);
s = size(format, &j);
++j;
print = _print(format, &j, list, buffer,
f, w, p, s);
if (print == -1)
return (-1);
p_chars += print;
}
}
print_buff(buffer, &index);
va_end(list);
return (p_chars);
}
