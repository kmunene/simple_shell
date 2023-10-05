#include "shell.h"
/**
 * main - Entry point of the program.
 * This function serves as the entry point for a simple command-line shell.
 * It repeatedly prompts the user for input, processes the input, and executes
 * commands until the user enters "exit" to exit the shell.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
	char *input;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			prompt_print();
			input = get_input();
			process_input(input);
			free(input);
		}
	}
	else
	{
		while (1)
		{
			input = get_input();
			process_input(input);
			free(input);
		}
	}

	return (0);
}
