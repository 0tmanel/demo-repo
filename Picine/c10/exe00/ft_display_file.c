#include <unistd.h>
#include <fcntl.h>
#define MAX_SIZE 100
int main (int argc, char**argv)
{
    char buffer[MAX_SIZE];
    if(argc == 1)
    {
        write(1, "File name missing.\n", 19);
        return -1; 
    }else if(argc > 2)
    {
        write(1, "Too many arguments.\n", 20);
        return -1;
    }
    if(argc == 2){

    int fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        return 1;
    }
    int numRead = read(fd, buffer, MAX_SIZE);
    if(numRead == -1)
    {
        write(1, "Cannot read file.\n", 18);
        return 1;
        close(fd);
    }
    buffer[numRead] = '\0';
        write(1, buffer, numRead);
      
    close(fd);
    }
     write(1, "\n", 1);
}