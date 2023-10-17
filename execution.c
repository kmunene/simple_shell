#include "shell.h"
/**
 * execute_command - Executes a command specified in cmd_args.
 * @cmd_args: Array of strings representing the command
 * and its arguments.
 * This function attempts to execute the command
 * specified in cmd_args. If the
 * execution fails, it will attempt to find the
 * command in the PATH environment
 * variable and try again. If all attempts fail,
 * it will print an error message
 * and exit.
 */
void execute_command(char **cmd_args)
{
	char path[1024], *env, *tok;

	env = my_getenv("PATH");
	tok = my_strtok(env, ":");

	while (tok != NULL)
	{
		manual_strcpy(path, tok);
		manual_strcat(path, "/");
		manual_strcat(path, cmd_args[0]);
		execve(path, cmd_args, NULL);
		tok = my_strtok(NULL, ":");
	}

	perror("./hsh");
	free(*cmd_args);
	exit(2);
}

/**
 * wait_for_command - Waits for the specified child
 * process to finish execution.
 * @pid: Process ID of the child process.
 * @context: Pointer to the Shell context structure.
 * This function waits for the child process
 * with the specified PID to finish
 * execution. It then updates the last_status
 * field in the Shell context based on
 * the exit status of the child process.
 */
void wait_for_command(pid_t pid, Shell *context)
{
	int stat, exit_stat;

	waitpid(pid, &stat, 0);

	if (WIFEXITED(stat))
	{
		exit_stat = WEXITSTATUS(stat);
		context->last_status = (exit_stat == 0) ? 0 : 2;
	}
	else
	{
		context->last_status = 2;
	}
}

/**
 * execution - Executes a command specified in
 * cmd_args and updates the context.
 * @cmd_args: Array of strings representing
 * the command and its arguments.
 * @context: Pointer to the Shell context structure.
 * This function creates a child process to execute
 * the command specified in
 * cmd_args. It then waits for the child process
 * to finish execution and updates
 * the context with the exit status of the command.
 */
void execution(char **cmd_args, Shell *context)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(cmd_args[0], cmd_args, NULL);
		execute_command(cmd_args);
	}
	else
	{
		wait_for_command(pid, context);
	}
}
