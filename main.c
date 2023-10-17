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

	while (1)
	{
		command = user_entries();
		handle_input(command, &context);
		free(command);
	}
	return (0);
}
