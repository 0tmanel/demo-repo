#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#define _30KO 30000
void display_error(char *prog, char *file)
{
    write(2, prog, strlen(prog));
    write(2, ": ", 2);
    write(2, file, strlen(file));
    write(2, ": ", 2);
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}
void display_file(int fd)
{
    char buffer[_30KO];
    ssize_t len;
    while ((len = read(fd, buffer, _30KO)) > 0)
    {
        write(1, buffer, len);
    }
    if (len == -1)
    {
        write(2, strerror(errno), strlen(strerror(errno)));
        write(2, "\n", 1);
    }
}
int main(int argc, char **argv)
{

    if (argc == 1)
    {
        display_file(STDIN_FILENO);
        //The constants STDIN_FILENO and STDOUT_FILENO are defined in <unistd.h>
        return 0;
    }

    int i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && !argv[i][1])
        {
            // Read from standard input if argument is '-'
            display_file(STDIN_FILENO);
        }
        else
        {

            int fd = open(argv[i], O_RDONLY);
            if (fd == -1)
            {
                display_error(basename(argv[0]), argv[i]);
                continue;
                //The continue statement immediately skips the rest of the current iteration of the loop and moves to the next iteration.
                //It does not exit the loop—it just jumps directly to the next file in the argument list.
                //Without continue:
                //The program would try to read fd even though open() failed, causing errors or crashes.

            }

            display_file(fd);
            close(fd);
        }
        i++;
    }
}
