#include <stdio.h>
#include <unistd.h>
#include "test2.c"
 int check(char *str)
 {
    int len = ft_strlen(str);
    if(len < 2)
    return 0;
    int i = 0;
    while(i < len)
    {
        int j = i + 1;
        while(j < len)
        {
            if(str[i] == str[j])
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
 }
 int ft_atoi_base(char *nbr, char *base_from)
 {
    int len = ft_strlen(base_from);
    int result = 0;
    int sign = 1;
    int i = 0;
    while((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
    i++;
    while(nbr[i] == '-' || nbr[i] == '+')
    {
        if(nbr[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    while(nbr[i] >= '0' && nbr[i] <= '9')
    {
        result = result * len + (nbr[i] - '0');
        i++;
    }
   
    return result * sign;

 }
char* ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(!check(base_from) || !check(base_to))
    return NULL;
    int result = ft_atoi_base(nbr, base_from);
    int length = calcu_nbr(result, base_to);
    char* string = ft_putnbr_base(result, length - 1, base_to);
    string[length] = '\0';
    return string;
}
int main()
{
   char nbr[]= "-6483648";
    char base_from[] = "0123456789";
    char base_to[] = "0123456789ABCDEF";
    char *array = ft_convert_base(nbr, base_from, base_to);
    printf("%s\n", array);
   // ft_convert_base(nbr, base_from, base_to);
}
