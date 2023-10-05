#include "shell.h"

/**
 * getenv_manual - Get the value of an environment variable.
 *
 * This function searches for an environment variable by name and returns its
 * value. If the variable is not found, it returns NULL.
 *
 * @name: The name of the environment variable to retrieve.
 * Return: A pointer to the value of the environment
 * variable, or NULL if not found.
 */
char *getenv_manual(const char *name)
{
	char *env_var;
	size_t name_length = 0;
	const char *name_pointer = name;
	char **environment;
	size_t index;

	/* Calculate the length of the variable name */
	while (*name_pointer != '\0')
	{
		name_length++;
		name_pointer++;
	}

	/* Iterate through the environment variables */
	for (environment = __environ; *environment != NULL; environment++)
	{
		env_var = *environment;

		/* Compare the variable name with the name parameter */
		for (index = 0; index < name_length; index++)
		{
			if (env_var[index] != name[index])
			{
				break;
			}
		}

		/* If a match is found, return the value of the variable */
		if (index == name_length && env_var[name_length] == '=')
		{
			return (&env_var[name_length + 1]);
		}
	}

	/* Variable not found, return NULL */
	return (NULL);
}

