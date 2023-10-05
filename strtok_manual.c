#include "shell.h"

/**
 * strtok_manual - Tokenize a string manually.
 *
 * This function tokenizes a string based on space (' ') and newline ('\n')
 * characters. It splits the input string into tokens and stores them in the
 * data_tokens array. The tokens are separated by space or newline characters.
 * Lines starting with '#' are ignored, and tokens within them are not stored.
 *
 * @data: The string to be tokenized.
 * @data_tokens: An array to store the resulting tokens.
 */

void strtok_manual(char *data, char *data_tokens[])
{
	int i = 0;
	char *start = data;
	int hash = 0;

	while (*data != '\0')
	{
		if (*data == ' ' || *data == '\n')
		{
			if (data != start && !hash)
			{
				*data = '\0';
				data_tokens[i++] = start;
			}
			start = data + 1;
		}
		else if (*data == '#')
		{
			hash = 1;
		}
		data++;
	}

	if (data != start && !hash)
	{
		data_tokens[i++] = start;
	}

	data_tokens[i] = NULL;
}

