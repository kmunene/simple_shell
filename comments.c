#include "shell.h"
/**
 * comments - Handle comments in the command
 * @command: Input command string
 */
void comments(char *command)
{
	int k;
	char *comment_pos = NULL;

	for (k = 0; command[k] != '\0'; k++)
	{
		if (command[k] == ' ' && command[k + 1] == '#')
		{
			comment_pos = command + k + 1;
			break;
		}
	}

	if (comment_pos != NULL)
	{
		*comment_pos = '\0';
	}
}

