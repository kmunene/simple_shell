#include "shell.h"
/**
 * my_strcmp - Compares two strings character by character.
 * @user_str: The first string to be compared.
 * @cmp_str: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if the first
 *         string is found, respectively, to be less than, to match, or be
 *         greater than the second string.
 */
int my_strcmp(const char *user_str, const char *cmp_str)
{
	while (*user_str != '\0' || *cmp_str != '\0')
	{
		if (*user_str != *cmp_str)
		{
			return ((*user_str > *cmp_str) ? 1 : -1);
		}
		user_str++;
		cmp_str++;
	}
	return (0);
}

