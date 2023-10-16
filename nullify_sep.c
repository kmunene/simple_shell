#include "shell.h"
/**
 * nullify_sep - Nullify separator positions
 * @sep_pos: Pointer to the position of separator
 * @and_pos: Pointer to the position of 'and' separator
 * @or_pos: Pointer to the position of 'or' separator
 */
void nullify_sep(char *sep_pos, char *and_pos, char *or_pos)
{
	if (sep_pos != NULL)
	{
		*sep_pos = '\0';
	}

	if (and_pos != NULL)
	{
		*and_pos = '\0';
	}

	if (or_pos != NULL)
	{
		*or_pos = '\0';
	}
}

