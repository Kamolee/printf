#include "main.h"


/**

 * _printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int _printable(char c)

{
if (c >= 32 && c < 127)
return (1);
return (0);
}
