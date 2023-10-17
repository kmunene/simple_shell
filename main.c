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
			if (my_strstr(command, "$?"))
			{
				handle_status(&context);
			} else if (my_strstr(command, "$$"))
			{
				handle_pid();
			} else
			{
				process_entries(command, &context);
			}
			free(command);
		}
	}
	else
	{
		command = user_entries();
		if (my_strstr(command, "$?"))
		{
			handle_status(&context);
		} else if (my_strstr(command, "$$"))
		{
			handle_pid();
		} else
		{
			process_entries(command, &context);
		}
		free(command);
	}
	return (0);
}
