#include "shell.h"
/**
 * my_getenv - Get the value of an environment variable
 * @target_name: Name of the environment variable
 *
 * Return: Value of the environment variable
 */
char *my_getenv(const char *target_name)
{
	char *target_value, **env_list;
	size_t i, target_length = 0;
	const char *name_ptr = target_name;

	while (*name_ptr != '\0')
	{
		target_length++;
		name_ptr++;
	}

	for (env_list = __environ; *env_list != NULL; env_list++)
	{
		target_value = *env_list;

		for (i = 0; i < target_length; i++)
		{
			if (target_value[i] != target_name[i])
			{
				break;
			}
		}

		if (i == target_length && target_value[target_length] == '=')
		{
			return (&target_value[target_length + 1]);
		}
	}

	return (NULL);
}

