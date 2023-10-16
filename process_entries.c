#include "shell.h"

/**
 * process_entries - Process command entries
 * @command: Input command to process
 */

void process_entries(char *command)
{
	char *sep_pos, *and_pos, *or_pos;
	char *args[256], *token;
	int i = 0, j, non_space = 0;

	comments(command);

	for (j = 0; command[j] != '\0'; j++)
	{
		if (command[j] != ' ')
		{
			non_space = 1;
			break;
		}
	}

	if (!non_space || command[0] == '#')
	{
		return;
	}

	sep_pos = my_strstr(command, " ; ");
	and_pos = my_strstr(command, " && ");
	or_pos = my_strstr(command, " || ");

	nullify_sep(sep_pos, and_pos, or_pos);

	token = my_strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = my_strtok(NULL, " ");
	}
	args[i] = NULL;

	special_cmds(args);
	sep_terms(sep_pos, and_pos, or_pos);
}

