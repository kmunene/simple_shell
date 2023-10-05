#include "shell.h"
/**
  * get_input - get input from the user
  * Return: user's input
  */
char *get_input(void)
{
	FILE *ptr = stdin;
	size_t bufsize = 256;
	char *input = NULL;
	ssize_t chars_noted;

	chars_noted = getline(&input, &bufsize, ptr);

	if (chars_noted == -1)
	{
		if (feof(ptr))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}

