#include "shell.h"
/**
 * main_loop - Main loop of the shell program.
 * @context: Pointer to a Shell context structure.
 * This function continuously prompts for user input,
 * processes commands,
 * and handles special commands like status and PID.
 * It uses the provided
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
 * main - Entry point of the shell program.
 * This function initializes the Shell context and
 * enters the main loop.
 * It checks if input is coming from a terminal,
 * and if so, starts the
 * interactive shell by calling main_loop.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	Shell context = {0};

	if (isatty(STDIN_FILENO))
	{
		main_loop(&context);
	}
	else
	{
		main_loop(&context);
	}
	return (0);
}
