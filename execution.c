#include "shell.h"
/**
 * execution - Execute the command
 * @cmd_args: List of command arguments
 * @context: last_status
 */

void execution(char **cmd_args, Shell *context)
{
	char path[1024], *env, *tok;
	int stat, exit_stat;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(cmd_args[0], cmd_args, NULL);
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
		exit(2);
	}
	else
	{
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
}


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


/**
 * sep_terms - Handle separator terms
 * @sep: Pointer to the position of separator
 * @and: Pointer to the position of 'and' separator
 * @context: last_status
 * @or: Pointer to the position of 'or' separator
 */
void sep_terms(char *sep, char *and, char *or, Shell *context)
{
	if (sep != NULL)
	{
		process_entries(sep + 3, context);
	}

	if (and != NULL && context == 0)
	{
		process_entries(and + 4, context);
	}

	if (or != NULL && context != 0)
	{
		process_entries(or + 3, context);
	}
}

/**
 * handle_status - Prints the last status
 * @context: last_status
 */
void handle_status(Shell *context)
{
	my_print('0' + context->last_status);
	my_print('\n');
}
