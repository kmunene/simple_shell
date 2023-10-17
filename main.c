#include "shell.h"
/**
 * main - Entry point of the shell program
 *
 * Return: Always returns 0 to indicate successful execution
 */
int main(void)
{
	char *command;
	Shell context = {0};

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			shell_prompt();
			command = user_entries();
			process_entries(command, &context);
			free(command);
		}
	}
	else
	{
		while (1)
		{
			command = user_entries();
			process_entries(command, &context);
			free(command);
		}
	}
	return (0);
}
