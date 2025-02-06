#include <unistd.h>
int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
char *ft_rev_print (char *str)
{
    int len = ft_strlen(str) - 1;
    
    int i = 0;
    while (len >= 0)
    {
     write(1, &str[len], 1);
        len--;   
    }
    return str;
}
int main (int argc, char **argv)
{
    if (argc == 2)
    {
        ft_rev_print(argv[1]);
       
    }
    write(1, "\n", 1);

}