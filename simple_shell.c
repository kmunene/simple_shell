#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int last_status = 0;

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


void execute_command(char **args) 
{
    char *path, *token;
    char executable_path[1024];
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
            snprintf(executable_path, sizeof(executable_path), "%s/%s", token, args[0]);
            execve(executable_path, args, NULL);
            token = strtok(NULL, ":");
        }

        perror("execve");
        exit(2);
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) 
        {
            int exit_status = WEXITSTATUS(status);
            last_status = (exit_status == 0) ? 0 : 2;
        } 
        else 
        {
            last_status = 2;
        }
    }
}



char* get_user_input() {
    char *command = NULL;
    size_t bufsize = 0;

    if (isatty(STDIN_FILENO)) {
        printf("#cisfun$ ");
        fflush(stdout);
    }

    if (getline(&command, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        } else {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    command[strcspn(command, "\n")] = '\0';
    return command;
}


void process_user_input(char *command) 
{
    char *separator_pos, *and_pos, *or_pos;
    char *args[256];
    char **env;

    int i = 0, j, k, contains_non_space;
    char *token;
  char *comment_pos = NULL;

    
    for ( k = 0; command[k] != '\0'; k++) 
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

    contains_non_space = 0;
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
separator_pos = strstr(command, " ; ");
    and_pos = strstr(command, " && ");
    or_pos = strstr(command, " || ");

    if (separator_pos != NULL) {
        *separator_pos = '\0';
    }

    if (and_pos != NULL) {
        *and_pos = '\0';
    }

    if (or_pos != NULL) {
        *or_pos = '\0';
    }

    token = strtok(command, " ");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        if (args[1] != NULL) {
            int exit_code = atoi(args[1]);
            free(command);
            exit(exit_code);
        } else {
            free(command);
            exit(last_status);
        }
    } else if (strcmp(args[0], "env") == 0) {
        env = __environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
    } else {
        execute_command(args);
    }
    if (separator_pos != NULL) {
        process_user_input(separator_pos + 3);
    }

    if (and_pos != NULL && last_status == 0) {
        process_user_input(and_pos + 4);
    }

    if (or_pos != NULL && last_status != 0) {
        process_user_input(or_pos + 3);
    }
    
}

void handle_status()
      {
        printf("%d\n", last_status);
      }
void handle_pid()
{
  printf("%d\n", getpid());
}
int main() {
    char *command;

    while (1) {
        command = get_user_input();
      if (strstr(command, "$?"))
      {
        handle_status();
        
      }
      else if (strstr(command, "$$"))
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
