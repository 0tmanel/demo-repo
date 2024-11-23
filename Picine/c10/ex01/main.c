#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    char buf[100];
    int fd;
    int result;
    int i = 1;
    if (argc == 1)
    {
        write(2, "File missing\n", 13);
    }

    while (argc > i)
    {
        char *base = basename(argv[i]);
        fd = open(argv[i], O_RDONLY);
        /*The error message "No such file or directory" typically corresponds to ENOENT,
         which stands for Error NO ENTry. This error code is returned by system calls
          like open(), stat(), or access() when the file or directory you're trying
           to access does not exist.*/
        if (fd == -1)
        {
            char *mss = strerror(errno);
             write(2, "Error opening file: ", 20);
            write(2, base, strlen(base));  // Print the base name of the file
            write(2, " - ", 3);
            write(2, mss, strlen(mss));
            write(2, "\n", 1);
        }
        else{

        while ((result = read(fd, buf, 100)) > 0)
        {
           
            write(1, buf, result);
        }
            if (result == -1)
            {
                char *messg = strerror(errno);
                write(2, "Read Error: ", 12);
                write(2, messg, strlen(messg));
                 write(2, " while reading file: ", 21);
                write(2, base, strlen(base));
                write(2, "\n", 1);
            }
            
        close(fd);
        }
        i++;
    }
    return 0;
}