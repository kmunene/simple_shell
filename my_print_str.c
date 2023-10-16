#include "shell.h"
/**
 * my_print_str - Print a string
 * @s: String to print
 */
void my_print_str(const char *s)
{
	while (*s != '\0')
	{
		my_print(*s);
		s++;
	}
}

