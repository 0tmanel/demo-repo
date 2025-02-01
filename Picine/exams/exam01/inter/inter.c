#include <unistd.h>
int pos(char* str, char c, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if( str[i] == c)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void inter(char*str, char*str2)
{
     
    int i = 0;
    while (str[i] != '\0')
    {
        int j = 0;
        while (str2[j] != '\0')
        {
            if (pos(str, str[i], i) == 1)
            {
                write(1, &str[i], 1);
                break;   
            }
            j++;
        }
        
        i++;
    }
    write(1, "\n", 1);
}
int main (int argc, char **argv)
{
    if(argc == 1)
    {
        write(1, "\n", 1);
    }
   inter(argv[1], argv[2]);

}
        /*
        int j = 0;
        while (argv[2][j] != '\0')
        {
            if(argv[1][i] == argv[2][j])
            {
                int k = 1;
                while (i > k)
                {
                    if(argv[1][k] == argv[1][i])
                    {
                        break;
                    }
                    k++;
                }
                if(str[k] == argv[1][i])
                break;
                else {

                write(1, &argv[2][j], 1);
                break;
                }

            }
            j++;
        }
        */