#include "shell.h"

char *my_strtok(char *user_str, const char *delim)
{
    static char *lastToken = NULL;
    char *d, *start;

    if (user_str != NULL)
    {
        lastToken = user_str;
    }
    if (lastToken == NULL)
    {
        return NULL;
    }
    start = lastToken;
    while (*lastToken != '\0')
    {
        d = find_delim(lastToken, delim);
        if (*d == '\0')
        {
            ++lastToken;
        } else
        {
            *lastToken = '\0';
            ++lastToken;
            if (start != lastToken - 1)
            {
                return start;
            } else
            {
                start = lastToken;
            }
        }
    }
    if (start == lastToken)
    {
        return NULL;
    } else
    {
        return start;
    }
}
