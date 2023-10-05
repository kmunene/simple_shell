#include "shell.h"
/**
 * custom_strstr - Custom implementation of strstr
 * @haystack: The string to be searched
 * @needle: The substring to search for
 * Return: Pointer
 */
char *custom_strstr(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		const char *h = haystack;
		const char *n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		if (!*n)
		{
			return ((char *)haystack);
		}

		haystack++;
	}

	return (NULL);
}

/**
 * process_input - Process the input command
 * @input: The input command string
 */
void process_input(char *input)
{

	if (comp_str(input, "env\n") == 1)
	{
		display_env();
	}

	handle_exit(input);


	if (custom_strstr(input, ";") != NULL)
	{
		handle_semicolon(input);
	}
	else if (custom_strstr(input, "&&") != NULL)
	{
		handle_and(input);
	}
	else if (custom_strstr(input, "||") != NULL)
	{
		handle_or(input);
	}
	else
	{
		exec_cmd(input);
	}
}

