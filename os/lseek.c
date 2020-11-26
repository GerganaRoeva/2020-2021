#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct
{
    char data;
    unsigned char nextElementAdress;
} block;

int main(int argc, char const *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    block buf;
    int next;
    while(buf.nextElementAdress != 0)
    {
        read(fd, &buf, 2);
        write(1, &buf.data, 1);
        lseek(fd, buf.nextElementAdress, SEEK_SET);
    }
    close(fd);
    return 0;
}
