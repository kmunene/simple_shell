#include "shell.h"
/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 on successful execution.
 */
int main(void)
{
	char *command;
	Shell context = {0};

	while (1)
	{
		if (isatty(fileno(stdout)))
		{
			shell_prompt();
		}

		command = user_entries();

		if (my_strstr(command, "$?"))
		{
			handle_status(&context);
		}
		else if (my_strstr(command, "$$"))
		{
			handle_pid();
		}
		else
		{
			process_entries(command, &context);
		}

		free(command);
	}

	return (0);
}
