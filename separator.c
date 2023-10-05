#include "shell.h"

/**
 * get_last_status - Retrieves the last recorded status of a command
 *
 * This function returns the value of the last recorded status of a command.
 *
 * Return: The last status code
 */
int get_last_status(void)
{
	int last_status = 0;

	return (last_status);
}

/**
 * handle_semicolon - Function to handle semicolon operator
 * @command: The input command string
 */
void handle_semicolon(char *command)
{
	char *cmd = strtok(command, ";");

	while (cmd != NULL)
	{
		exec_cmd(cmd);
		cmd = strtok(NULL, ";");
	}
}

/**
 * handle_and - Function to handle and operator
 * @command: The input command string
 */
void handle_and(char *command)
{
	char *cmd = strtok(command, "&&");

	while (cmd != NULL)
	{
		exec_cmd(cmd);
		if (WEXITSTATUS(get_last_status()) != 0)
		{
			break;
		}
		cmd = strtok(NULL, "&&");
	}
}

/**
 * handle_or - Function to handle or operator
 * @command: The input command string
 */
void handle_or(char *command)
{
	char *cmd = strtok(command, "||");

	while (cmd != NULL)
	{
		exec_cmd(cmd);
		cmd = strtok(NULL, "||");
	}
}


