#include "main.h"
#include <unistd.h>

void print_buff(char buffer[], int *index);


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
/* write(1, &format[j], 1);*/
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
print = handle_print(format, &j, list, buffer,
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



/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @index: Index at which to add next char
 */
void print_buff(char buffer[], int *index)
{
if (*index > 0)
write(1, &buffer[0], *index);
*index = 0;
}
