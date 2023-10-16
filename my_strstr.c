#include "shell.h"

/**
 * my_strstr - Finds the first occurrence of the
 * substring 's_str' in the string 'u_str'
 * @u_str: Pointer to the source string to be searched
 * @s_str: Pointer to the substring to be found
 *
 * Return: If the substring is found, it returns,
 * a pointer to the beginning of the
 * substring in 'u_str'. If the substring is not found, it returns NULL.
 */
char *my_strstr(const char *u_str, const char *s_str)
{
		const char *u, *s;

		if (*s_str == '\0')
		{
			return ((char *)u_str);
		}

		while (*u_str)
		{
			u = u_str;
			s = s_str;

			while (*u && *s && *u == *s)
			{
				u++;
				s++;
			}
			if (*s == '\0')
			{
				return ((char *)u_str);
			}

			u_str++;
		}

	return (NULL);
}

