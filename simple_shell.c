#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int last_status = 0;
void process_user_input(char *command);



int my_print(char c)
{
  return (write(1, &c, 1));
}

void shell_prompt() 
{
    if (isatty(STDIN_FILENO)) 
    {
      int i;
      char prompt[] = "odec$ ";

      for (i = 0; prompt[i] != '\0'; i++)
        {
          my_print(prompt[i]);
        }
        fflush(stdout);
    }
}
int my_strcmp(const char* str1, const char* str2)
{
    while (*str1 != '\0' || *str2 != '\0')
      {
        if (*str1 != *str2) 
        {
            return (*str1 > *str2) ? 1 : -1;
        }
        str1++;
        str2++;
    }
    return 0;
}

size_t my_strcspn(const char *str, const char *reject) {
    const char *s, *r;
    size_t count = 0;

    for (s = str; *s != '\0'; ++s) {
        for (r = reject; *r != '\0'; ++r) {
            if (*s == *r) {
                return count;
            }
        }
        ++count;
    }

    return count;
}

char* my_strchr(const char* str, int character)
{
    while (*str != '\0')
      {
        if (*str == character) 
        {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}
char* my_strstr(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return (char*)haystack; /* If the needle is an empty string, return the haystack.*/
    }

    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char*)haystack; /* Found a match.*/
        }

        haystack++;
    }

    return NULL; /* If no match is found, return NULL.*/
}
void manual_strcpy(char *dest, const char *src) 
{
    while ((*dest++ = *src++))
      {
        ;
    }
}


void manual_strcat(char *dest, const char *src)
{
    while (*dest)
      {
        dest++;
    }
    while ((*dest++ = *src++))
      {
        ;
    }
}

void execute_command(char **args)
{
    char executable_path[1024], *path, *token;
    int status;

    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) 
    {
        execve(args[0], args, NULL);

        path = getenv("PATH");
        token = strtok(path, ":");
        while (token != NULL) 
        {
            manual_strcpy(executable_path, token);  
            manual_strcat(executable_path, "/");   
            manual_strcat(executable_path, args[0]); 
            execve(executable_path, args, NULL);
            token = strtok(NULL, ":");
        }
        perror("execve");
        exit(2);
    } else
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            last_status = (exit_status == 0) ? 0 : 2;
        } else
        {
          last_status = 2;
        }
    }
}


char* get_user_input() 
{
    char *command = NULL;
    size_t bufsize = 0;

    if (getline(&command, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        } else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    command[my_strcspn(command, "\n")] = '\0';
    return command;
}

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;
  
    while (*str == ' ') {
        str++;
    }

    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }
  
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

void handle_exit(char **args)
{
    if (args[1] != NULL) 
    {
        int exit_code = my_atoi(args[1]);
      free(*args);
        exit(exit_code);
    } else
    {
        free(*args);
        exit(last_status);

    }
}

void my_print_str(const char *str) {
    while (*str != '\0') {
        my_print(*str);
        str++;
    }
}

void handle_env() {
    char **env = __environ;
    while (*env != NULL) {
        my_print_str(*env);
        my_print('\n');
        env++;
    }
}

void handle_comments(char *command)
{
    int k;
    char *comment_pos = NULL;
    for (k = 0; command[k] != '\0'; k++) {
        if (command[k] == ' ' && command[k+1] == '#') {
            comment_pos = command + k + 1;
            break;
        }
    }

    if (comment_pos != NULL) 
    {
        *comment_pos = '\0';
    }
}

void handle_special_commands(char **args) 
{
    if (my_strcmp(args[0], "exit") == 0)
    {
        handle_exit(args);
    } else if (my_strcmp(args[0], "env") == 0)
    {
        handle_env();
    } else 
    {
        execute_command(args);
    }
}

void process_separator_conditions(char *separator_pos, char *and_pos, char *or_pos) 
{
    if (separator_pos != NULL)
    {
        process_user_input(separator_pos + 3);
    }

    if (and_pos != NULL && last_status == 0)
    {
        process_user_input(and_pos + 4);
    }

    if (or_pos != NULL && last_status != 0)
    {
        process_user_input(or_pos + 3);
    }
}

void nullify_separator_positions(char *separator_pos, char *and_pos, char *or_pos) 
{
    if (separator_pos != NULL)
    {
        *separator_pos = '\0';
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

void process_user_input(char *command) 
{
    char *separator_pos, *and_pos, *or_pos;
    char *args[256], *token;
    int i = 0, j, contains_non_space = 0;

    handle_comments(command);

    for (j = 0; command[j] != '\0'; j++)
      {
        if (command[j] != ' ')
        {
            contains_non_space = 1;
            break;
        }
    }

    if (!contains_non_space || command[0] == '#')
    {
        return;
    }

    separator_pos = my_strstr(command, " ; ");
    and_pos = my_strstr(command, " && ");
    or_pos = my_strstr(command, " || ");

    nullify_separator_positions(separator_pos, and_pos, or_pos);

    token = strtok(command, " ");

    while (token != NULL)
      {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    handle_special_commands(args);
    process_separator_conditions(separator_pos, and_pos, or_pos);
}


void handle_status()
      {
        my_print('0' + last_status);
        my_print('\n');
      }
void handle_pid() 
{
    int pid = getpid();
    int numDigits = 0, i, *digits;
    int temp = pid;

    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    digits = malloc(numDigits * sizeof(int));

    temp = pid; 

    for ( i = numDigits - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    for ( i = 0; i < numDigits; i++) {
        my_print('0' + digits[i]);
    }
    my_print('\n');

    free(digits); 
}


int main() 
{
    char *command;

    while (1)
      {
         shell_prompt();
        command = get_user_input();
      if (my_strstr(command, "$?"))
      {
        handle_status();
      }
      else if (my_strstr(command, "$$"))
          {
            handle_pid();
          }
      else
      {
         process_user_input(command);
      }
       free(command);
    }

    return 0;
}
