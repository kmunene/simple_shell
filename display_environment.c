#include "shell.h"

/**
 * display_env - Display environment variables.
 *
 * This function prints the current envirnment variable to the standard output.
 * It iterates through the envirnment variable array and prints each variables
 * name and value.
 * Return void
 */
void display_env(void)
{
	char **env = __environ;
	char *temp;

	while (*env != NULL)
	{
		temp = *env;

		while (*temp != '\0')
		{
			printchar(*temp);
			temp++;
		}
		printchar('\n');
		env++;
	}
}


