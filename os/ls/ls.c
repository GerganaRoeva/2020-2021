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
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>

int A = 0;
int l = 0;
int R = 0;

int only_ls(int argc, char * const argv[])
{
    for(int i = 1; i < argc; i++)
        if(argv[i][0] != '-') return 0;
    
    return 1;
}

int fnamescount(int argc, char * const argv[])
{
    int count = 0;
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-') continue;
        count++;
    }
    return count;
}

int count_total(char * const name)
{   
    struct stat data;
    int total;

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
    else if(S_ISDIR(data.st_mode))
    {
        DIR* dir;
        struct dirent *dir_inf; 

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
            char file_name[PATH_MAX];
            sprintf(file_name, "%s/%s", name, dir_inf->d_name);
            struct stat data_check;

            if(stat(file_name, &data_check) == -1)
            {
                const char* msg1 = "ls: cannot access ";
                const char* msg2 = dir_inf->d_name;

                char* msg;
                msg = malloc(strlen(msg1)+1+strlen(msg2));
                strcpy(msg, msg1);
                strcat(msg, msg2);

                perror(msg);
                free(msg);
            }  
            else 
            {
                if(!strcmp(dir_inf->d_name, ".") || !strcmp(dir_inf->d_name, ".."))    continue;
                total += data_check.st_blocks;
            }
        }
        closedir(dir);
    }
    return total;
}

void printlinfo(struct stat data)
{
    if(S_IRUSR  & data.st_mode)      printf("r");
    else                             printf("-");
    if(S_IWUSR  & data.st_mode)      printf("w");
    else                             printf("-");
    if(S_IXUSR  & data.st_mode)      printf("x");
    else                             printf("-");
    if(S_IRGRP  & data.st_mode)      printf("r");
    else                             printf("-");
    if(S_IWGRP  & data.st_mode)      printf("w");
    else                             printf("-");
    if(S_IXGRP  & data.st_mode)      printf("x");
    else                             printf("-");
    if(S_IROTH  & data.st_mode)      printf("r");
    else                             printf("-");
    if(S_IWOTH  & data.st_mode)      printf("w");
    else                             printf("-");
    if(S_IXOTH  & data.st_mode)      printf("x");
    else                             printf("-");

    printf(" %ld ", data.st_nlink);

    struct passwd *pw = getpwuid(data.st_uid);
    struct group  *gr = getgrgid(data.st_gid);
    if( pw != 0)                     printf("%s ", pw->pw_name);
    if( gr != 0)                     printf("%s ", gr->gr_name);

    printf("%ld ", data.st_size);

    struct tm *time;
    time = localtime(&data.st_mtim.tv_sec);
    int size = 100;
    char timestr[size];
    strftime(timestr,size, "%B %e %H:%M", time);
    printf("%s", timestr);
}

void ls(char * const name, int argc, int count)
{
    struct stat data;

    // count++;
    if(count > 0)
    printf("\n"); 

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
    else
    {
        if(S_ISREG(data.st_mode ))         printf("-");
        if(S_ISBLK(data.st_mode ))         printf("b");
        if(S_ISCHR(data.st_mode ))         printf("c");
        if(S_ISSOCK(data.st_mode))         printf("s");
        if(S_ISFIFO(data.st_mode))         printf("p");
        if(S_ISLNK(data.st_mode ))         printf("l");
        if(l && !S_ISDIR(data.st_mode))    printlinfo(data);
        if(!S_ISDIR(data.st_mode))         printf(" %s\n", name);

        

        if(S_ISDIR(data.st_mode))
        {
            DIR* dir;
            struct dirent *dir_inf; 

            if (argc > 1) printf("%s:\n", name);

            if(l) printf("total %d\n", count_total(name)/2);


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
                if(!A && dir_inf->d_name[0] == '.')                                    continue;
                if(!strcmp(dir_inf->d_name, ".") || !strcmp(dir_inf->d_name, ".."))    continue;

                if(dir_inf->d_type == DT_REG )      printf("-");
                if(dir_inf->d_type == DT_BLK )      printf("b");
                if(dir_inf->d_type == DT_CHR )      printf("c");
                if(dir_inf->d_type == DT_SOCK)      printf("s");
                if(dir_inf->d_type == DT_FIFO)      printf("p");
                if(dir_inf->d_type == DT_LNK )      printf("l");
                if(dir_inf->d_type == DT_DIR )      printf("d");

                char file_name[PATH_MAX];
                sprintf(file_name, "%s/%s", name, dir_inf->d_name);

                if(stat(file_name, &data) == -1)
                {
                    const char* msg1 = "ls: cannot access ";
                    const char* msg2 = dir_inf->d_name;

                    char* msg;
                    msg = malloc(strlen(msg1)+1+strlen(msg2));
                    strcpy(msg, msg1);
                    strcat(msg, msg2);

                    perror(msg);
                }
                if(l)           printlinfo(data);
                printf(" %s\n", dir_inf->d_name);

                // if(R && dir_inf->d_type == DT_DIR) ls(file_name, argc, count);

            }
            closedir(dir);
        }
    }
}

void lsR()
{

}

int main(int argc, char * const argv[])
{
    int opt;
    int count = 0;
    
    while((opt = getopt(argc, argv, "AlR")) != -1) 
    { 
        switch(opt)
        { 
            case 'A': A = 1;     break;
            case 'l': l = 1;     break;
            case 'R': R = 1;     break;
        } 
    }

    int files = fnamescount(argc, argv);
    
    for(int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') continue;  
        ls(argv[i], files, count);
        count++;
    }

    if(only_ls(argc, argv)) 
    {
        char buff[100];
        getcwd(buff, 100);
        ls(buff, files, count);
        count++;
    }

    return 0;
}
