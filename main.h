#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)i

#define BUFF_SIZE 1
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1
/**
 * struct fm - Struct op
 *
 * @fm: The format.
 * @fn: The function associated.
 */
struct fm
{
char fm;
int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fm fm_t - Struct op
 *
 * @fm: The format.
 * @fm_t: The function associated.
 */
typedef struct fm fm_t;
int _printf(const char *format, ...);
int handle_print(const char *fm, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
