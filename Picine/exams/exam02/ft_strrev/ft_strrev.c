#include <stdio.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
char    *ft_strrev(char *str)
{
    int i = 0; 
    int j = ft_strlen(str) - 1;
    while (i < j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return str;
}
int main ()
{
    char str[] = "hello world";
    char *string = ft_strrev(str);
    printf("%s\n", string);
}