#include  <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#define _30KO 30000

int main (int argc, char **argv)
{
    
    if(argc == 1)
    {
       return 1;
    }
    
    int i = 1;    
        while (i < argc)
        {
            char buffer[_30KO] ;
            char* str = basename(argv[i]);
        int fd = open(argv[i], O_RDWR);
        if(fd == -1)
        {
            //strerror(errno);
            return 1;
        }
        int len = read(fd, buffer, _30KO);
        if(len == -1)
        {
            //strerror(errno);
            return 1;
        }
        buffer[len] = '\0';
        write(fd, buffer, len);
        write(1, "\n", 1);
        close(fd);
        i++;
        }
}
