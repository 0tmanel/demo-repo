#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <xlocale.h>
#define SIZE 1024
void printf_err(char *prog, char *argv)
{
    write(2, prog, strlen(prog));
    write(2, ": ", 2);
    write(2, argv, strlen(argv));
    write(2, ": ", 2);
    write(2, strerror(errno), strlen(strerror(errno)));
    write(1, "\n", 1);
}
int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            i++;
        while (str[i] == '-' || str[i] == '+')
            i++;
        while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10;
            result += str[i] - '0';
            i++;
        }
    return result;
}
int main(int argc, char **argv)
{

    if (argc == 1)
    {
        return 1;
    }
    if (strcmp(argv[1], "-c") == 0)
    {
    int fd = open(argv[3], O_RDONLY);
    if (fd == -1)
    {
        printf_err(basename(argv[0]), argv[2]);
        return 1;
    }

        int number = ft_atoi(argv[2]);
        if (number <= 0)
        {
            write(2, "Invalid byte count\n", 19);
            return 1;
        }
        if (lseek(fd, -number, SEEK_END) == -1)
        {
            printf_err(argv[0], argv[3]);
            close(fd);
            return 1;
        }
        char *buffer = malloc((number + 1) * sizeof(char));
        if (!buffer)
        {
            write(2, "Memory allocation failed\n", 25);
            return 1;
        }
        int readL = read(fd, buffer, number);
        if (readL == -1)
        {
            printf_err(argv[0], argv[3]);
            free(buffer);
            close(fd);
            return 1;
        }

        buffer[readL] = '\0';
        write(1, buffer, number);
        free(buffer);
        close(fd);
    }
    else {
         int fd = open(argv[2], O_RDONLY);
        int number = ft_atoi(argv[1]);
        if (number <= 0)
        {
            write(2, "Invalid byte count\n", 19);
            return 1;
        }
        if (lseek(fd, -number, SEEK_END) == -1)
        {
            printf_err(argv[0], argv[2]);
            close(fd);
            return 1;
        }
        char *buffer = malloc((number + 1) * sizeof(char));
        if (!buffer)
        {
            write(2, "Memory allocation failed\n", 25);
            close(fd);
            return 1;
        }
        int readL = read(fd, buffer, number);
        if (readL == -1)
        {
            printf_err(argv[0], argv[2]);
            free(buffer);
            close(fd);
            return 1;
        }

        buffer[readL] = '\0';
        write(1, buffer, number);
        free(buffer);
    close(fd);
    }
    return 0;
}
