#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int last_status = 0;
void process_entries(char *command);



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

int my_strcmp(const char* user_str, const char* cmp_str)
{
    while (*user_str != '\0' || *cmp_str != '\0')
      {
        if (*user_str != *cmp_str) 
        {
            return ((*user_str > *cmp_str) ? 1 : -1);
        }
        user_str++;
        cmp_str++;
    }
    return (0);
}


size_t my_strcspn(const char *a_str, const char *m_str)
{
    const char *a, *m;
    size_t count = 0;

    for (a = a_str; *a != '\0'; ++a)
      {
        for (m = m_str; *m != '\0'; ++m)
          {
            if (*a == *m)
            {
                return (count);
            }
        }
        ++count;
    }

    return (count);
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
    return (NULL);
}

char* my_strstr(const char* u_str, const char* s_str)
{
    const char *u, *s;
  
    if (*s_str == '\0') 
    {
        return ((char*)u_str); 
    }

    while (*u_str) 
    {
        u = u_str;
        s = s_str;

        while (*u && *s && *u == *s) 
        {
            u++;
            s++;
        }

        if (*s == '\0')
        {
            return (char*)u_str; 
        }

        u_str++;
    }

    return (NULL);
}

void manual_strcpy(char *to, const char *from) 
{
    while ((*to++ = *from++))
      {
        ;
    }
}


void manual_strcat(char *to, const char *from)
{
    while (*to)
      {
        to++;
    }
    while ((*to++ = *from++))
      {
        ;
    }
}

char *my_getenv(const char *target_name)
{
    char *target_value, **env_list;
    size_t i, target_length = 0;
    const char *name_ptr = target_name;
  
    while (*name_ptr != '\0')
    {
        target_length++;
        name_ptr++;
    }

    for (env_list = __environ; *env_list != NULL; env_list++)
    {
        target_value = *env_list;

        for (i = 0; i < target_length; i++)
        {
            if (target_value[i] != target_name[i])
            {
                break;
            }
        }

        if (i == target_length && target_value[target_length] == '=')
        {
            return (&target_value[target_length + 1]);
        }
    }

    return (NULL);
}

void execution(char **cmd_args)
{
    char path[1024], *env, *tok;
    int stat;

    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) 
    {
        execve(cmd_args[0], cmd_args, NULL);

        env = my_getenv("PATH");
        tok = strtok(env, ":");
        while (tok != NULL) 
        {
            manual_strcpy(path, tok);  
            manual_strcat(path, "/");   
            manual_strcat(path, cmd_args[0]); 
            execve(path, cmd_args, NULL);
            tok = strtok(NULL, ":");
        }
        perror("./hsh");
        exit(2);
    } else
    {
        waitpid(pid, &stat, 0);

        if (WIFEXITED(stat))
        {
            int exit_stat = WEXITSTATUS(stat);
            last_status = (exit_stat == 0) ? 0 : 2;
        } else
        {
            last_status = 2;
        }
    }
}

char* user_entries() 
{
    char *data = NULL;
    size_t size = 0;

    if (getline(&data, &size, stdin) == -1)
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

    data[my_strcspn(data, "\n")] = '\0';
    return (data);
}


int my_atoi(const char *s)
{
    int res = 0;
    int sign = 1;
  
    while (*s == ' ')
    {
        s++;
    }

    if (*s == '-' || *s == '+') 
    {
        if (*s == '-') 
        {
            sign = -1;
        }
        s++;
    }
  
    while (*s >= '0' && *s <= '9') 
    {
        res = res * 10 + (*s - '0');
        s++;
    }

    return (sign * res);
}


void my_exit(char **cmds)
{
    int exit_num;
  
    if (cmds[1] != NULL) 
    {
      exit_num = my_atoi(cmds[1]);
      free(*cmds);
      exit(exit_num);
    } else
    {
        free(*cmds);
        exit(last_status);

    }
}

void my_print_str(const char *s)
{
    while (*s != '\0')
    {
        my_print(*s);
        s++;
    }
}

void my_env() 
{
    char **env = __environ;
    while (*env != NULL) 
    {
        my_print_str(*env);
        my_print('\n');
        env++;
    }
}

void comments(char *command)
{
    int k;
    char *comment_pos = NULL;
    for (k = 0; command[k] != '\0'; k++) 
    {
        if (command[k] == ' ' && command[k+1] == '#')
        {
            comment_pos = command + k + 1;
            break;
        }
    }

    if (comment_pos != NULL) 
    {
        *comment_pos = '\0';
    }
}

void special_cmds(char **cmd_args) 
{
    if (my_strcmp(cmd_args[0], "exit") == 0)
    {
        my_exit(cmd_args);
    } else if (my_strcmp(cmd_args[0], "env") == 0)
    {
        my_env();
    } else 
    {
        execution(cmd_args);
    }
}

void sep_terms(char *sep_pos, char *and_pos, char *or_pos) 
{
    if (sep_pos != NULL)
    {
        process_entries(sep_pos + 3);
    }

    if (and_pos != NULL && last_status == 0)
    {
        process_entries(and_pos + 4);
    }

    if (or_pos != NULL && last_status != 0)
    {
        process_entries(or_pos + 3);
    }
}

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

void process_entries(char *command) 
{
    char *sep_pos, *and_pos, *or_pos;
    char *args[256], *token;
    int i = 0, j, non_space = 0;

    comments(command);

    for (j = 0; command[j] != '\0'; j++)
      {
        if (command[j] != ' ')
        {
            non_space = 1;
            break;
        }
    }

    if (!non_space || command[0] == '#')
    {
        return;
    }

    sep_pos = my_strstr(command, " ; ");
    and_pos = my_strstr(command, " && ");
    or_pos = my_strstr(command, " || ");

    nullify_sep(sep_pos, and_pos, or_pos);

    token = strtok(command, " ");

    while (token != NULL)
      {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    special_cmds(args);
    sep_terms(sep_pos, and_pos, or_pos);
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

    while (temp > 0) 
    {
        temp /= 10;
        numDigits++;
    }

    digits = malloc(numDigits * sizeof(int));

    temp = pid; 

    for ( i = numDigits - 1; i >= 0; i--)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }

    for ( i = 0; i < numDigits; i++) 
    {
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
        command = user_entries();
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
         process_entries(command);
      }
       free(command);
    }

    return 0;
}
