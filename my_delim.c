#include "shell.h"
char *find_delim(char *lastToken, const char *delim)
{
    const char *d = delim;
    while (*d != '\0' && *d != *lastToken) 
    {
        ++d;
    }
    return (char *)d;
}
