#include "shell.h"
/**
 * exec_cmd - Execute a command.
 * @input: The input command as a string.
 */
void exec_cmd(char *input)
{
	pid_t small_pid;
	char *tokens[256];
	char *executable;
	char *const *args;
	char *path_env;
	int status;

	strtok_manual(input, tokens);

	small_pid = fork();

	if (small_pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (small_pid == 0)
	{
		executable = tokens[0];
		args = tokens;

		path_env = getenv_manual("PATH");

		if (executable[0] == '/')
		{
			exec_helper(executable, args);
		}
		else
		{
			cmd_execution(executable, args, path_env);
		}
	}
	else
	{
		/* Wait for the child process to complete */
		waitpid(small_pid, &status, 0);
	}
}

