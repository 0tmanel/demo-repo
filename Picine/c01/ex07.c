#include <stdio.h>
int ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;

}
int main ()
{
    char str [] = "hello world";
   printf("%d", ft_putstr(str));
}