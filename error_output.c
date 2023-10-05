#include "shell.h"

/**
 * error_output - Display an error message.
 *
 * This function is responsible for displaying an error message indicating
 * that a command execution has failed.
 * Return void
 */
void error_output(void)
{
	int k;
	char error_display[] = "Error executing command.\n";

	/* Iterate through the error message string and print each character */
	for (k = 0; error_display[k] != '\0'; k++)
	{
		/* Print the current character from the error message */
		printchar(error_display[k]);
	}
}

