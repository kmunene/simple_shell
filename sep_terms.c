#include "shell.h"
/**
 * sep_terms - Handle separator terms
 * @sep: Pointer to the position of separator
 * @and: Pointer to the position of 'and' separator
 * @context: last_status
 * @or: Pointer to the position of 'or' separator
 */
void sep_terms(char *sep, char *and, char *or, Shell *context)
{
	if (sep != NULL)
	{
		process_entries(sep + 3, context);
	}

	if (and != NULL && context == 0)
	{
		process_entries(and + 4, context);
	}

	if (or != NULL && context != 0)
	{
		process_entries(or + 3, context);
	}
}
