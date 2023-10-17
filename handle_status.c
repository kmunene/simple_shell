#include "shell.h"
/**
 * handle_status - Prints the last status
 * @context: last_status
 */
void handle_status(Shell *context)
{
	my_print('0' + context->last_status);
	my_print('\n');
}
