#include "shell.h"
/**
  * prompt_print - print the prompt
  */
void prompt_print(void)
{
	int i;
	char prompt[] = "codec$ ";

	for (i = 0; prompt[i] != '\0'; i++)
	{
		printchar(prompt[i]);
	}
}
