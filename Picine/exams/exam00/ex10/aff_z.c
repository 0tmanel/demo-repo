#include <unistd.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int i = 0;
    int found = 0;
     if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] == 'z')
            {
                write(1, "z\n", 2);
                found++;
                break;
            }
            i++;
        }
        if(!found)
        {
            write(1, "z\n", 2);
        }
        
    }else {
        
        write(1, "z\n", 2);
    }
}