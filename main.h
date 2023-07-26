#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#define BUFF_SIZE 1024
#define SLONG 2
#define SSHORT 1
#define FMINUS 1
#define FPLUS 2
#define FZERO 4
#define FHASH 8
#define FSPACE 16
#define UNUSED(x) (void)(x)
#define S_LONG 2
#define S_SHORT 1



int _printf(const char *format, ...);
int flags(const char *format, int *i);
int width(const char *format, int *i, va_list list);
int precision(const char *format, int *i, va_list list);
int size(const char *format, int *i);
int digit(char c);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size);
int pchar(va_list types, char buffer[],
int f, int w, int p, int s);
int pstring(va_list types, char buffer[],
int f, int w, int p, int s);
int _percent(va_list types, char buffer[],
int f, int w, int p, int s);
int _int(va_list types, char buffer[],
int f, int w, int p, int s);
int pbinary(va_list types, char buffer[],
int f, int w, int p, int s);
int punsigned(va_list types, char buffer[],
int f, int w, int p, int s);
int Octal(va_list types, char buffer[],
int f, int w, int p, int s);
int _reverse(va_list types, char buffer[],
int f, int w, int p, int s);
int _rot13string(va_list types, char buffer[],
int f, int w, int p, int s);
int _pointer(va_list types, char buffer[],
int f, int w, int p, int s);
int _non_printable(va_list types, char buffer[],
int f, int w, int p, int s);
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size);
int p_hexadecimal(va_list types, char buffer[],
int f, int w, int p, int s);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);


/**

 * struct fmt - Struct op

 *

 * @fmt: The format.

 * @fn: The function associated.

 */

struct fmt

{

        char fmt;

        int (*fn)(va_list, char[], int, int, int, int);

};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;
#endif
