#include "shell.h"
/**
 * my_strtok - This is a manual strtok
 * @user_str: user's input
 * @delim: delimeter
 * Return: tokenized input
 */

char *my_strtok(char *user_str, const char *delim)
{
	static char *lastToken;
	char *d, *start;

	if (user_str != NULL)
	{
		lastToken = user_str;
	}
	if (lastToken == NULL)
	{
		return (NULL);
	}
	start = lastToken;
	while (*lastToken != '\0')
	{
		d = find_delim(lastToken, delim);
		if (*d == '\0')
		{
			++lastToken;
		} else
		{
			*lastToken = '\0';
			++lastToken;
			if (start != lastToken - 1)
			{
				return (start);
			}
				start = lastToken;
		}
	}
	if (start == lastToken)
	{
		return (NULL);
	}
		return (start);
}
