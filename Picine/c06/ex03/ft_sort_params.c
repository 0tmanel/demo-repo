#include <unistd.h>
int ft_strcmp(char *s1, char *s2)
 {
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return *s1 - *s2;
 }
void ft_swap(char *a, char *b)
{
    char t;
    t = *a;
    *a = *b;
    *b = t;
}
void ft_sort(int argc, char *argv[])
{

    if (argc > 1)
    {
        int i = 1;
        while (i < argc)
        {
            int j = i + 1;
            while (j < argc)
            {
                if (ft_strcmp(argv[i], argv[j]) > 0)
                {
                    ft_swap(argv[i], argv[j]);
                }
                j++;
            }
            i++;
        }
    }
}
 int main (int argc, char*argv[])
 {
    ft_sort(argc, argv);
     
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