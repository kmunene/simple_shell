#include "shell.h"
/**
 * my_strcspn - Computes the length of the maximum initial segment of the
 *              string that consists entirely of characters not in the
 *              string m_str.
 * @a_str: The string to be scanned.
 * @m_str: The string containing the characters to match.
 *
 * Return: The length of the segment that does not contain any character from
 *         m_str.
 */
size_t my_strcspn(const char *a_str, const char *m_str)
{
	const char *a, *m;
	size_t count = 0;

	for (a = a_str; *a != '\0'; ++a)
	{
		for (m = m_str; *m != '\0'; ++m)
		{
			if (*a == *m)
			{
				return (count);
			}
		}
		++count;
	}

	return (count);
}

