//------------------------------------------------------------------------
// NAME: Gergana Roeva
// CLASS: XIb
// NUMBER: 8
// PROBLEM: #1
// FILE NAME: tail2_otzip1.c
// FILE PURPOSE:
// Реализация стандартната UNIX команда tail.
//------------------------------------------------------------------------
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define std 1
char a = 0;

//------------------------------------------------------------------------
// FUNCTION: check_open
// проверява дали файл може да се отвори
// PARAMETERS:
// файлов дескриптор и име на файла
//------------------------------------------------------------------------
int check_open(int fd, const char* name)
{
    if (fd == -1)
    {
        int len1 = strlen("tail: cannot open '");
                int len2 = strlen(name);
                int len3 = strlen("' for reading");

                char *err = malloc(len1 + len2 + len3);
                memcpy(err, "tail: cannot open '", len1);
                memcpy(err + len1, name, len2);
                memcpy(err + len1 + len2, "' for reading", len3);
                perror(err);
                free(err);

                return -1;
    }
    return 0;
}

//------------------------------------------------------------------------
// FUNCTION: check_read
// проверява дали файл може да се чете
// PARAMETERS:
// връщана стойност на функ. read и име на файла
//------------------------------------------------------------------------
int check_read(int b, const char* name)
{
    if(b == -1)
                {

                    int len1 = strlen("tail: error reading '");
                    int len2 = strlen(name);

                    char *err = malloc(len1 + len2);
                    memcpy(err, "tail: error reading '", len1);
                    memcpy(err + len1, name, len2);
                    memcpy(err + len1 + len2, "'", strlen("'"));
                    perror(err);
                    free(err);

                    return -1;
                }
                return 0;
}

//------------------------------------------------------------------------
// FUNCTION: check_close
// проверява дали файл може да се затвори
// PARAMETERS:
// връщана стойност на функ. close и име на файла
//------------------------------------------------------------------------
int check_close(int c, const char* name)
{
    if(c == -1)
    {

        int len1 = strlen("tail: error reading '");
        int len2 = strlen(name);

        char *err = malloc(len1 + len2);
        memcpy(err, "tail: error reading '", len1);
        memcpy(err + len1, name, len2);
        memcpy(err + len1 + len2, "'", strlen("'"));
        perror(err);
        free(err);

        return -1;
    }

    return 0;
}

//------------------------------------------------------------------------
// FUNCTION: head
// изкарва брой редове
// PARAMETERS:
// файлов дескриптор и броя редове, които трябва да се изведат на стандартния изход.
//------------------------------------------------------------------------
void head(int fd, int lines, char *name)
{
    int count = 0; 
    while(count < lines)
    {
        read(fd, &a, sizeof(char));
        if(a == '\n')
        {
            count++;
        }
        int c = write(std, &a, sizeof(char));
        if(c == -1)
        {
            int len1 = strlen("tail: error reading '");
            int len2 = strlen(name);

            char *err = malloc(len1 + len2);
            memcpy(err, "tail: error reading '", len1);
            memcpy(err + len1, name, len2);
            memcpy(err + len1 + len2, "'", strlen("'"));
            perror(err);
            free(err);
        }
    }
}

//------------------------------------------------------------------------
// FUNCTION: name_of_file
// изкарва на стандартния изход име файл
// PARAMETERS:
// името на файла
//------------------------------------------------------------------------
void name_of_file(char const *name)
{
    write(std, "==> ", sizeof("==> "));
    write(std, name, strlen(name));        
    write(std, " <==\n", sizeof(" <==\n"));
}

//------------------------------------------------------------------------
// FUNCTION: count_lines
// брои редове
// PARAMETERS:
// името на файла, чиито редове искаме да прочетем
//------------------------------------------------------------------------
int count_lines(char const *name)
{
    int fd = open(name, O_RDONLY);
    if(check_open(fd, name) == -1)return -1;

    int count = 0;
    int b = 1;

    while(1)
    {
        b = read(fd, &a, sizeof(a));
        if(check_read(b, name) == -1)return -1;
        if(b == 0) break;
        if(a == '\n') count++;
    }
    int c = close(fd);
    if(check_close(c, name) == -1)return -1;
    return count;
}

//------------------------------------------------------------------------
// FUNCTION: last_ten_lines
// извежда на стандартния изход последните 10 реда на файл
// PARAMETERS:
// името на файла, чиито редове искаме да изведем и броя редове, които съдържа
//------------------------------------------------------------------------
void last_ten_lines(char const *name , int lines)
{
    int fd = open(name, O_RDONLY);
    int lines_to_read = 10;
    int start_line = lines - lines_to_read;
    int b = 1;
    int count_lines = 0;

    while(b != 0)
    {
        b = read(fd, &a, sizeof(a));

        if(a == '\n')
        {
            count_lines++;
        }
        if(count_lines == start_line && a == '\n') read(fd, &a, sizeof(a));
        int c;
        
        if(count_lines >= start_line)
        {
            c = write(std, &a, sizeof(char));
            if(c == -1)
            {
                int len1 = strlen("tail: error reading '");
                int len2 = strlen(name);

                char *err = malloc(len1 + len2);
                memcpy(err, "tail: error writing '", len1);
                memcpy(err + len1, name, len2);
                memcpy(err + len1 + len2, "'", strlen("'"));
                perror(err);
                free(err);

                return;
            }
        }
        if(count_lines == lines) break;
        
    }
    close(fd);
}

//------------------------------------------------------------------------
// FUNCTION: read_write
// чете и извежда на стандартния изход последните 10 реда от въведеното от стандартиния вход
// PARAMETERS:
// индекса във argv и броя аргументи
//------------------------------------------------------------------------
void read_write(int i, int argc, const char* name)
{
    if(argc != 1 && i != 1) name_of_file("standard input");

    char* buf = (char*)malloc(sizeof(char));

    read(0, &a, sizeof(a));
    strcpy(buf, &a);

    int size = 1;
    int b = 1;
    int count = 0;

    while(b != 0)
    {
        b = read(0, &a, sizeof(a));
        size++;
        buf = realloc(buf, size*sizeof(a));
        strcat(buf, &a);
    }

    if(buf[size] == '\n') count = 0;
    int start_indx = 0;
    for(int i = size; i > 0; i--)
    {
        if(buf[i] == '\n') count ++;
        if(buf[size - 1] == '\n' && count == 11) {start_indx = i;}
        if(buf[size] != '\n' && count == 9) {start_indx = i;}
    }

        if(count <= 10)
        {
            for(int i = 0; i < size - 1; i++)
            {
                int c = write(std, &buf[i], sizeof(buf[i]));
                if(c == -1)
                {
                    int len1 = strlen("tail: error writing '");
                    int len2 = strlen(name);

                    char *err = malloc(len1 + len2);
                    memcpy(err, "tail: error writing '", len1);
                    memcpy(err + len1, name, len2);
                    memcpy(err + len1 + len2, "'", strlen("'"));
                    perror(err);
                    free(err);

                    return;
                }
            }
            if(i != 0 && i != argc - 1) write(std, "\n", sizeof("\n"));

        }
        else
        {
            for(; start_indx < size - 1; start_indx++)
            {
                int c = write(std, &buf[start_indx], sizeof(buf[start_indx]));
                if(c == -1)
                {
                    int len1 = strlen("tail: error writing '");
                    int len2 = strlen("-");

                    char *err = malloc(len1 + len2);
                    memcpy(err, "tail: error writing '", len1);
                    memcpy(err + len1, "-", len2);
                    memcpy(err + len1 + len2, "'", strlen("'"));
                    perror(err);
                    free(err);

                    return;
                }   
            }
            if(i != 0 && i != argc - 1) write(std, "\n", sizeof("\n"));

        }
       /* if((start_indx == size && buf[start_indx] != '\n') || (i == size && buf[i] != '\n'))
        {
            write(std, "\n", sizeof("\n"));
        }*/
           /* //
            if(i != argc - 1 )
            {
                //write(std, "\n", sizeof("\n"));
            }*/

            free(buf);
}



int main(int argc, char const *argv[])
{
    if(argc == 1)
    {
        read_write(0, argc, "-");
    }
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-") != 0)
        {                   
            

            int lines = count_lines(argv[i]);
            if(lines == -1) continue;
            if(argc > 2) name_of_file(argv[i]);
            char* name = (char* )argv[i];
            if(lines <= 10)
            {
                int fd = open(argv[i], O_RDONLY);
                head(fd, lines, name);
                close(fd);
            }
            else
            {
                last_ten_lines(argv[i], lines);
            }
            if(i != argc - 1)
            {
                write(std, "\n", sizeof("\n"));
            }
        }

        if(strcmp(argv[i], "-") == 0)
        {
           read_write(i, argc, argv[i]);
        } 
    }

    return 0;
}
