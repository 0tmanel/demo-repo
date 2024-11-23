#include <stdio.h>
#include <unistd.h>
int ft_str_is_alpha(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main ()
{
    char str[] = "123445i"; 
    int result = ft_str_is_alpha(str);
    printf("%d", result);
}