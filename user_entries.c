#include "shell.h"
/**
 * user_entries - Read user input from stdin
 *
 * Return: User input as a string
 */
char *user_entries(void)
{
	char *data = NULL;
	size_t size = 0;
	int i;

	if (isatty(STDIN_FILENO))
	{
		char prompt[] = "odec$ ";

		for (i = 0; prompt[i] != '\0'; i++)
		{
			my_print(prompt[i]);
		}
	}

	if (getline(&data, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		} else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	data[my_strcspn(data, "\n")] = '\0';
	return (data);
}
