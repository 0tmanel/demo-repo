#include <stdio.h>
 char *ft_strupcase(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
    return str;
 }
int main ()
{
    char str[] = "hello world";
    char *retu = ft_strupcase(str);
    printf("%s\n", retu);
}