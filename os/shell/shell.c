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
        printf("$ ");

        char *cmdline = NULL;
        size_t size = 0;
        int get_res = getline(&cmdline, &size, stdin);
        if(get_res == -1) return 0;

        pid_t fork_res = fork();

        if(fork_res == -1) perror("fork");

        if(fork_res == 0)
        {
            char ** arr;
            arr = parse_cmdline(cmdline);

            // printf("%s", arr[0]);
            
            int exec_res = execvp(arr[0], arr);
            
            if (exec_res == -1)
            {
                perror(arr[0]);
                
            }
            free(arr);
        }

        wait(NULL);
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
    while (pch != 0)
    {
        arr = realloc(arr, (i+1)*sizeof(pch));
        arr[i] = malloc(strlen(pch) + 1); 
        strcpy(arr[i], pch);
        // printf ("%s\n",arr[i]);
        pch = strtok (NULL, " \n");
        i++;
    }

    arr[i] = realloc(arr[i], sizeof(NULL));
    arr[i] = NULL;

    return arr;

}

