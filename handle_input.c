#include "shell.h"
/**
 * handle_input - Handles user input based on special commands.
 * @command: The user input command.
 * @context: Pointer to the Shell context.
 */
void handle_input(char *command, Shell *context)
{
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
}
