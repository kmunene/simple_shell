#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct Shell - Represents the shell context.
 * @last_status: The exit status of the last command executed.
 */
typedef struct Shell
{
	int last_status;
} Shell;

char *my_strtok(char *user_str, const char *delim);
char *find_delim(char *lastToken, const char *delim);
void process_entries(char *command, Shell *context);
int my_print(char c);
void shell_prompt(void);
void manual_strcat(char *to, const char *from);
int my_strcmp(const char *user_str, const char *cmp_str);
size_t my_strcspn(const char *a_str, const char *m_str);
char *my_strchr(const char *str, int character);
char *my_strstr(const char *u_str, const char *s_str);
void manual_strcpy(char *to, const char *from);
char *my_getenv(const char *target_name);
void execution(char **cmd_args, Shell *context);
char *user_entries(void);
int my_atoi(const char *s);
void my_exit(char **cmds, Shell *context);
void my_print_str(const char *s);
void my_env(void);
void comments(char *command);
void special_cmds(char **cmd_args,  Shell *context);
void sep_terms(char *sep, char *and, char *or, Shell *context);
void nullify_sep(char *sep_pos, char *and_pos, char *or_pos);
void handle_status(Shell *context);
void handle_pid(void);
int main(void);

#endif /* SHELL_H */

