#include "shell.h"
/**
 * main_loop - Main loop of the shell program.
 * @context: Pointer to a Shell context structure.
 *
 * This function continuously prompts for user input, processes commands,
 * and handles special commands like status and PID. It uses the provided
 * Shell context to keep track of the shell's state.
 */
void main_loop(Shell *context)
{
	char *command;

	while (1)
	{
		shell_prompt();
		command = user_entries();

		if (my_strstr(command, "$?"))
		{
			handle_status(context);
		}
		else if (my_strstr(command, "$$"))
		{
			handle_pid();
		}
		else
		{
			process_entries(command, context);
		}

		free(command);
	}
}

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
		main_loop(&context);
	}
	else
	{
		while (1)
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
	}
	return (0);
}
