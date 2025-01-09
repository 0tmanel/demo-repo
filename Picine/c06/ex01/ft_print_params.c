#include <unistd.h>
int main (int argc, char *argv[])
{
    if (argc > 1)
    {
        int i = 1;
        while(i < argc)
        {
            int j = 0;
            while (argv[i][j]!= '\0')
            {
                write(1, &argv[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        } 
    }
}