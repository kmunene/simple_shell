#include "shell.h"
/**
 * my_print - Function that prints a character to the standard output.
 * @c: The character to be printed.
 *
 * Return: The number of bytes written. On error, -1 is returned.
 */
int my_print(char c)
{
	return (write(1, &c, 1));
}

