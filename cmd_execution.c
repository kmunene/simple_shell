#include "shell.h"
/**
 * cmd_execution - execute the command
 * @exec: pointer
 * @exec_args: This is a pointer to a constant pointer
 * @path: pointer to a char array that contains list of directories
 */
void cmd_execution(char *exec, char * const *exec_args, char *path)
{
	char path_buf[256], *path_tk = path, *path_st = path_tk;
	char *cur_dir, *path_buf_ptr, *exec_ptr;
	int exec_stat;

	while (*path_tk != '\0')
	{
		if (*path_tk == ':')
		{
			cur_dir = path_st;
			path_buf_ptr = path_buf;

			while (cur_dir != path_tk)
				*path_buf_ptr++ = *cur_dir++;
			*path_buf_ptr++ = '/';
			exec_ptr = exec;

			while (*exec_ptr != '\0')
				*path_buf_ptr++ = *exec_ptr++;
			*path_buf_ptr = '\0';

			exec_stat = execve(path_buf, exec_args, NULL);

			if (exec_stat == -1 && errno != ENOENT)
			{
				perror("execve");
				error_output();
				exit(EXIT_FAILURE);
			}
			path_st = path_tk + 1;
		}
		path_tk++;
	}

	cmd_err_msg();
}

