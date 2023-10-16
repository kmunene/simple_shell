#include "shell.h"
/**
 * my_atoi - Converts a string to an integer
 * @s: Input string.
 *
 * Return: The integer value of the string
 */
int my_atoi(const char *s)
{
	int res = 0;
	int sign = 1;

	while (*s == ' ')
	{
		s++;
	}

	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
		{
			sign = -1;
		}
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}

	return (sign * res);
}

