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
        if(get_res == -1) 
        {
            free(cmdline);
            return -1;
        }

        pid_t fork_res = fork();

        if(fork_res == -1)
        {
            free(cmdline);
            perror("fork");
            continue;
        }

        if(fork_res == 0)
        {
            char ** arr;
            arr = parse_cmdline(cmdline);

            if(arr == NULL) return 0;

            int exec_res = execvp(arr[0], arr);
            
            if (exec_res == -1)
            {
                perror(arr[0]);
                free(cmdline);
                free(arr);
                exit(EXIT_FAILURE);
                
            }
            free(arr);
            free(cmdline);
        }

        pid_t wait_res = wait(NULL);

        
        if (wait_res == -1)
        {
            free(cmdline);
            perror("wait");
            continue;
        }

        free(cmdline);

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
	char ** arr= (char**)malloc(sizeof(char*));
    
    while (pch != 0)
    {
        arr = (char**)realloc(arr, (i + 1)*sizeof(char*));
        arr[i] = malloc(strlen(pch) + 1); 
        strcpy(arr[i], pch);
        pch = strtok (NULL, " \n");
        i++;
    }

    arr = realloc(arr, i * sizeof(char*) + sizeof(NULL));
    arr[i] = NULL;

    return arr;

}
