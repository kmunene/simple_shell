#include "shell.h"
/**
 * my_exit - Exits the program
 * @cmds: Commands to process
 * @context: last_status
 */
void my_exit(char **cmds, Shell *context)
{
	int exit_num;

	if (cmds[1] != NULL)
	{
		exit_num = my_atoi(cmds[1]);
		free(*cmds);
		exit(exit_num);
	}
	else
	{
		free(*cmds);
		exit(context->last_status);
	}
}
