#include <stdio.h>
#include <unistd.h>
char *ft_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
int main ()
{
    char str[] = "hello"; 
   ft_strupcase(str);
    int i = 0;
    while (str[i] != 0)
    {
        write (1, &str[i], 1);
        i++;
    }
}
    