#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char **parse_cmdline( const char *);

int main(int argc, char const *argv[])
{
    while(1)
    {
        write(STDOUT_FILENO, "$ ", strlen("$ "));
        // char cmdline[260] = {0};
        char *cmdline = NULL;
        size_t size = 0;
        
        // scanf("%s", cmdline);
        if(getline(&cmdline, &size, stdin) == -1) break;
        // read(STDIN_FILENO, cmdline, sizeof(cmdline));

        // if(read_res == 0) break;
        int i;
        // for(i = 0; cmdline[i] != '\0'; i++);

    

        //printf("%c", cmdline[2]);
        
        char ** arg;
        arg = parse_cmdline(cmdline);

        // printf("%s", arg[0]);

        pid_t fork_res = fork();

        if(fork_res == -1)
        {
            perror("fork");
            continue;
        }

        if(fork_res == 0)
        {
            int exec_res = execvp(arg[0], arg);
            if (exec_res == -1)
            {
                perror(arg[0]);
                continue;
            }
    
        }

        wait(NULL);

        free(arg);
    }


    
    return 0;
}

char **parse_cmdline(const char *cmdline)
{
    char in_use[strlen(cmdline) + 1];
    strcpy(in_use, cmdline);

    int i = 0;
    char * pch;

    pch = strtok(in_use ," \n");
    char ** arr= malloc(sizeof(pch));
    while (pch != NULL)
    {

        arr = realloc(arr, (i+1)*sizeof(pch));
        // arr[i] = pch;
        arr[i] = malloc(strlen(pch) + 1); 
        strcpy(arr[i], pch);
        // printf ("%s\n",arr[i]);
        pch = strtok (NULL, " ");
        i++;
    }

    return arr;

}
