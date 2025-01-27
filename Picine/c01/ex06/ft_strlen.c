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
int main ()
{
    char str[] = "hello world";
    int len =  ft_strlen(str);
    printf("%d\n", len);
}