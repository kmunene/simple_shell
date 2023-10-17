#include "shell.h"
/**
 * shell_prompt - Function to display a shell prompt if STDIN is a terminal.
 */
void shell_prompt(void)
{
	if (isatty(STDIN_FILENO) != 0)
	{
		int i;
		char prompt[] = "odec$ ";

		for (i = 0; prompt[i] != '\0'; i++)
		{
			my_print(prompt[i]);
		}
	}
}
