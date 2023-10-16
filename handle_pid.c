#include "shell.h"
/**
 * handle_pid - Prints the current process ID
 */
void handle_pid(void)
{
	int pid = getpid();
	int num_digits = 0, i, *digits;
	int temp = pid;

	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}

	digits = malloc(num_digits * sizeof(int));

	temp = pid;

	for (i = num_digits - 1; i >= 0; i--)
	{
		digits[i] = temp % 10;
		temp /= 10;
	}

	for (i = 0; i < num_digits; i++)
	{
		my_print('0' + digits[i]);
	}
	my_print('\n');

	free(digits);
}

