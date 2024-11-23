#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include  <string.h>
#include <libgen.h>
int main (int argc, char* argv[])
{
    int fd;
    char buff[1024];
    char* base = basename(argv[1]);
    if (argc < 2)
    {
       // char* mess = strerror(errno);
        write (2, "file missing\n", 12);
        return 1;
    }
   
        fd = open(argv[1], O_RDONLY);
        if(fd == -1)
        {
            char* mess = strerror(errno);
            write (2, base, strlen(base));
            write(2, " - ", 3);
            write (2, mess, strlen(mess));
             write(2, "\n", 1);
             return 1;
        }
        off_t size = lseek(fd, 31, SEEK_SET);
        int si = -8;
        int result;
        size = lseek(fd, si, SEEK_END);
        while ((result = read(fd, buff, 1024)) > 0)
        {
            write(1, buff, result);
        }
        if(result == -1)
        {
            char* mess = strerror(errno);
            write (2, base, strlen(base));
            write(2, " - ", 3);
            write (2, mess, strlen(mess));
             write(2, "\n", 1);
             return 1;
        }
        
    
    if (fd != -1) {
        close(fd);
    }

    return 0;
}