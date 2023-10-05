#include "shell.h"
/**
 * handle_exit - Handles the 'exit' command in the shell.
 * @input: The user input.
 */
void handle_exit(char *input)
{
	int exit_code;

	if (comp_str(input, "exit\n") == 1)
	{
		free(input);
		exit(0);
	}
	else if (str_n_cmp(input, "exit ", 5) == 0)
	{
		exit_code = custom_atoi(input + 5);
		free(input);
		exit(exit_code);
	}
}

/**
 * custom_atoi - Converts a string to an integer
 * @str: Input string
 *
 * Return: The converted integer value
 */
int custom_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i++] == '-') ? -1 : 1;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
	}

	return (sign * result);
}

/**
 * str_n_cmp - Compares at most n characters of two strings
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of characters to compare
 * Return: int
 */
int str_n_cmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);

		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}

	return (0);
}

