#include "shell.h"
/**
  * cmd_err_msg - print the error message
  * Return void
  */
void cmd_err_msg(void)
{
	int i;
	char error_display[] = "No such file or directory\n";

	for (i = 0; error_display[i] != '\0'; i++)
	{
		printchar(error_display[i]);
	}
}

