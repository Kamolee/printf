#include "main.h"
#include <unistd.h>

/**
 *  * print_buff - Prints the contents of the buffer if it exist
 *   * @buffer: Array of chars
 *    * @index: Index at which to add next char
 *     */
void print_buff(char buffer[], int *index)
{
if (*index > 0)
write(1, &buffer[0], *index);
*index = 0;
}
