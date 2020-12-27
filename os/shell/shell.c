#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

char **parse_cmdline( const char *);

int main(int argc, char const *argv[])
{
    while(1)
    {
        write(STDOUT_FILENO, "$ ", strlen("$ "));
        char cmdline[260] = {0};
        int read_res = read(STDIN_FILENO, cmdline, sizeof(cmdline));
        if(read_res == 0)
        {
            break;
        } 
        // printf("%s", cmdline);
        
        char ** arg;
        arg = parse_cmdline(cmdline);

        // printf("%s", arg[0]);

        pid_t fork_res = fork();

        if(fork_res == -1)
        {
            perror("fork");
            continue;
        }
        else
        {
            int exec_res = execvp(arg[0], arg);
            if (exec_res == -1)
            {
                perror(arg[0]);
            }
        }
        

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

    pch = strtok(in_use ," ");
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
