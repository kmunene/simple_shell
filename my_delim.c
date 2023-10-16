#include "shell.h"
/**
 * find_delim - finds the delimeter
 * @lastToken: keeps record of the current token
 * @delim: delimeter
 * Return: d
 */
char *find_delim(char *lastToken, const char *delim)
{
	const char *d = delim;

	while (*d != '\0' && *d != *lastToken)
	{
		++d;
	}
	return ((char *)d);
}
