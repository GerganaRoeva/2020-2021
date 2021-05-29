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
#include <errno.h>

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

int only_ls(int argc, char * const argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] != '-') return 0;
    }
    return 1;
}

void info()
{

}

void ls(char * const name, int argc)
{
    struct stat data;

    if(stat(name, &data) == -1)
    {
        const char* msg1 = "ls: cannot access ";
        const char* msg2 = name;

        char* msg;
        msg = malloc(strlen(msg1)+1+strlen(msg2));
        strcpy(msg, msg1);
        strcat(msg, msg2);

        perror(msg);
    }

    if(S_ISREG(data.st_mode ))    printf("- %s\n", name);
    if(S_ISBLK(data.st_mode ))    printf("b %s\n", name);
    if(S_ISCHR(data.st_mode ))    printf("c %s\n", name);
    if(S_ISSOCK(data.st_mode))    printf("s %s\n", name);
    if(S_ISFIFO(data.st_mode))    printf("p %s\n", name);
    if(S_ISLNK(data.st_mode ))    printf("l %s\n", name);

    if(S_ISDIR(data.st_mode))
    {
        DIR* dir;
        struct dirent *dir_inf; 

        if (argc > 2) printf("%s:\n", name);

        if((dir = opendir(name)) == NULL)
        {
            const char* msg1 = "ls: cannot open directory ";
            const char* msg2 = name;

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

    for(int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') continue;
        if (i != 1) printf("\n");
        
        ls(argv[i], argc);
        
    }

    if(only_ls(argc, argv)) 
    {
        char buff[100];
        getcwd(buff, 100);
        ls(buff, argc);
    }
    return 0;
}
