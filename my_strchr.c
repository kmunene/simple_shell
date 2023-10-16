#include "shell.h"
/**
 * my_strchr - Locates the first occurrence of a character in a string.
 * @str: The string to be searched.
 * @character: The character to be located.
 *
 * Return: A pointer to the first occurrence of the character in the string.
 *         If the character is not found, returns NULL.
 */
char *my_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

