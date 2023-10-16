#include "shell.h"

/**
 * manual_strcpy - Copies a string from 'from' to 'to'
 * @to: Pointer to the destination string
 * @from: Pointer to the source string
 */
void manual_strcpy(char *to, const char *from)
{
	while ((*to++ = *from++))
	{
		;
	}
}

