#include "shell.h"
/**
 * my_env - Print the environment variables
 */
void my_env(void)
{
	char **env = __environ;

	while (*env != NULL)
	{
		my_print_str(*env);
		my_print('\n');
		env++;
	}
}
