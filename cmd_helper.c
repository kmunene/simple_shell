#include "shell.h"
/**
 * exec_helper - execute the command
 * @exec: pointer
 * @exec_args: This is a pointer to a constant pointer
 */
void exec_helper(char *exec, char * const *exec_args)
{
	int exec_stat = execve(exec, exec_args, NULL);

	if (exec_stat == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
