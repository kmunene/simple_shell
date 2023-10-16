#include "shell.h"
/**
 * execution - Execute the command
 * @cmd_args: List of command arguments
 */

void execution(char **cmd_args)
{
	char path[1024], *env, *tok;
	int stat;
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
			int exit_stat = WEXITSTATUS(stat);

			int last_status = (exit_stat == 0) ? 0 : 2;
		}
		else
		{
			last_status = 2;
		}
	}
}


/**
 * my_exit - Exits the program
 * @cmds: Commands to process
 */
void my_exit(char **cmds)
{
	int last_status = 0;
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
                exit(last_status);
        }
}


/**
 * sep_terms - Handle separator terms
 * @sep_pos: Pointer to the position of separator
 * @and_pos: Pointer to the position of 'and' separator
 * @or_pos: Pointer to the position of 'or' separator
 */
void sep_terms(char *sep_pos, char *and_pos, char *or_pos)
{
	int last_status = 0;
        if (sep_pos != NULL)
        {
                process_entries(sep_pos + 3);
        }

        if (and_pos != NULL && last_status == 0)
        {
                process_entries(and_pos + 4);
        }

        if (or_pos != NULL && last_status != 0)
        {
                process_entries(or_pos + 3);
        }
}


/**
 * handle_status - Prints the last status
 */
void handle_status(void)
{
	int last_status = 0;
        my_print('0' + last_status);
        my_print('\n');
}
