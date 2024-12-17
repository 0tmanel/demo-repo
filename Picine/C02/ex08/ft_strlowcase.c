#include <stdio.h>
 char *ft_strlowcase(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    return str;
 }
int main ()
{
    char str[] = "HELLO WORLD";
    char *retu = ft_strlowcase(str);
    printf("%s\n", retu);
}