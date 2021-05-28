//--------------------------------------------
// NAME: Gergana Roeva
// CLASS: XIb
// NUMBER: 8
// PROBLEM: #4
// FILE NAME: ls.c
// FILE PURPOSE:
// Целта на задачате е да се реализира стандартната UNIX комадна ls с добавена функционалност.
//---------------------------------------------
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

#define DT_UNKNOWN       0
#define DT_FIFO          1
#define DT_CHR           2
#define DT_DIR           4
#define DT_BLK           6
#define DT_REG           8
#define DT_LNK          10
#define DT_SOCK         12
#define DT_WHT          14

#define S_IFMT  00170000
#define S_IFSOCK 0140000
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)

int A = 0;

void ls(int argc, char * const argv[])
{
    struct stat data;

    for(int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') continue;

        if(stat(argv[i], &data) == -1)
        {
            const char* msg1 = "ls: cannot access ";
            const char* msg2 = argv[i];

            char* msg;
            msg = malloc(strlen(msg1)+1+strlen(msg2));
            strcpy(msg, msg1);
            strcat(msg, msg2);

            perror(msg);
            continue;
        }

        if(S_ISREG(data.st_mode ))    printf("- %s\n", argv[i]);
        if(S_ISBLK(data.st_mode ))    printf("b %s\n", argv[i]);
        if(S_ISCHR(data.st_mode ))    printf("c %s\n", argv[i]);
        if(S_ISSOCK(data.st_mode))    printf("s %s\n", argv[i]);
        if(S_ISFIFO(data.st_mode))    printf("p %s\n", argv[i]);
        if(S_ISLNK(data.st_mode ))    printf("l %s\n", argv[i]);

        if(S_ISDIR(data.st_mode))
        {
            DIR* dir;
            struct dirent *dir_inf;
    
            if (i != 1) printf("\n");
            printf("%s:\n", argv[i]);

            if((dir = opendir(argv[i])) == NULL)
            {
                const char* msg1 = "ls: cannot open directory ";
                const char* msg2 = argv[i];

                char* msg;
                msg = malloc(strlen(msg1)+1+strlen(msg2));
                strcpy(msg, msg1);
                strcat(msg, msg2);

                perror(msg);
            }
            else while((dir_inf = readdir(dir)) != NULL)
            {
                if(A == 0 && dir_inf->d_name[0] == '.')                                continue;
                if(!strcmp(dir_inf->d_name, ".") || !strcmp(dir_inf->d_name, ".."))    continue;

                if(dir_inf->d_type == DT_REG )      printf("- %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_BLK )      printf("b %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_CHR )      printf("c %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_SOCK)      printf("s %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_FIFO)      printf("p %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_LNK )      printf("l %s\n", dir_inf->d_name);
                if(dir_inf->d_type == DT_DIR )      printf("d %s\n", dir_inf->d_name);
            }

            closedir(dir);

        }
    }
    
}


int main(int argc, char * const argv[])
{
    int opt;
    
    while((opt = getopt(argc, argv, "AlR")) != -1) 
    { 
        switch(opt)
        { 
            case 'A': A = 1;                break;
            case 'l': printf("opt -l\n");   break;
            case 'R': printf("opt -R\n");   break;
        } 
    }

    ls(argc, argv);

    return 0;

}
