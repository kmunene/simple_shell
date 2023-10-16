#include "shell.h"
/**
 * main - Entry point function that runs the main program.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *command;

	while (1)
	{
		shell_prompt();
		command = user_entries();
		if (my_strstr(command, "$?"))
		{
			handle_status();
		}
		else if (my_strstr(command, "$$"))
		{
			handle_pid();
		}
		else
		{
			process_entries(command);
		}
		free(command);
	}

	return (0);
}

