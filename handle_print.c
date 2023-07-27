#include "main.h"
#include <unistd.h>

/**
 * _print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @f: Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: 1 or 2;
 */

int _print(const char *fmt, int *ind, va_list list, char buffer[],
int f, int w, int p, int s)
{
int i;
int unknow_len = 0;
int printed_chars = -1;
fmt_t fmt_types[] = {
{'c', pchar}, {'s', pstring}, {'%', _percent},
{'i', _int}, {'d', _int}, {'b', pbinary},
{'u', punsigned}, {'o', Octal}, {'x', p_hexadecimal},
{'X', print_hexa_upper}, {'p', _pointer}, {'S', _non_printable},
{'r', _reverse}, {'R', _rot13string}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*ind] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buffer, f, w, p, s));
if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (w)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}
