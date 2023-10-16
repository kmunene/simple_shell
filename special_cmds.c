#include "shell.h"
/**
 * special_cmds - Execute special commands
 * @cmd_args: List of command arguments
 */
void special_cmds(char **cmd_args)
{
	if (my_strcmp(cmd_args[0], "exit") == 0)
	{
		my_exit(cmd_args);
	}
	else if (my_strcmp(cmd_args[0], "env") == 0)
	{
		my_env();
	}
	else
	{
		execution(cmd_args);
	}
}

