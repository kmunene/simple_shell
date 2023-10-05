#include "shell.h"

/**
 * comp_str - Compare two strings for equality, It compares two strings,
 *  to check whether they're equal or not.
 *
 * This function compares two strings character by character and returns 1
 * if they are equal and 0 if they are not.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 1 if the strings are equal, 0 otherwise.
 */
int comp_str(char *str1, char *str2)
{
	int i = 0;

	/* Continue comparing characters until */
	/* a null terminator is reached in both strings */
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		/* If the characters at the current position are not equal, return 0 */
		if (str1[i] != str2[i])
		{
			return (0);
		}
		i++;
	}

	/* If the loop completes, it means the strings are equal, so return 1 */
	return (1);
}


