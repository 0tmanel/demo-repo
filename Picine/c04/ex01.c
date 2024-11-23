#include <unistd.h>
#include <stdio.h>
int ft_atoi(char *str)
{
    int sign = 0;
    int result = 0;
    int i = 0;
    while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
    {
        i++;
    } 
    while (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign++;
        }
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9')
    {
       result *= 10;
       result +=  str[i] - 48;
        i++;
    }
    if(sign % 2)

    return result;
    else 
    return -result;
    

}
int main ()
{
    char str[] = "--+--1234";
    int result = ft_atoi(str);
    printf("%d", result);
}