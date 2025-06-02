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

       ////////////////////////////////////////
//        #include <unistd.h>
// int is_found(char* str, int i, char c)
// {
//     int j = 0;
//     while(i > j)
//     {
//         if(str[j] == c)
//         {
//             return 0;
//         }
//         j++;
//     }
//     return 1;
// }
// int is_found2(char* str, char c)
// {
//     int j = 0;
//     while(str[j])
//     {
//         if(str[j] == c)
//         {
//             return 1;
//         }
//         j++;
//     }
//     return 0;
// }
// void inter(char * s1, char* s2)
// {
//     int i = 0;
//     while(s1[i])
//     {
//         if(is_found(s1, i, s1[i]) && is_found2(s2, s1[i]))
//         {
//             write(1, &s1[i], 1);
//         }
//         i++;
//     }

// }
// int main (int argc, char **av)
// {
//     inter(av[1], av[2]);
//     write(1, "\n", 1);
// }