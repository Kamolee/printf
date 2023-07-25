#include "main.h"
/**
 * flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int flags(const char *format, int *i)

{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int j;
int c;
int f = 0;
const char FCHAR[] = {'-', '+', '0', '#', ' ', '\0'};
const int FARRAY[] = {FMINUS, FPLUS, FZERO, FHASH, FSPACE, 0};
for (c = *i + 1; format[c] != '\0'; c++)
{
for (j = 0; FCHAR[j] != '\0'; j++)
if (format[c] == FCHAR[j])
{
f |= FARRAY[j];
break;
}
if (FCHAR[j] == 0)
break;
}
*i = c - 1;
return (f);
}
