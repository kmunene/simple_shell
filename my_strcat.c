#include "shell.h"
/**
 * manual_strcat - Concatenates two strings
 * @to: The destination string to which the source string is appended
 * @from: The source string to be appended to the destination string
 */
void manual_strcat(char *to, const char *from)
{
	while (*to)
	{
		to++;
	}

	while ((*to++ = *from++))
	{
		;
	}
}

