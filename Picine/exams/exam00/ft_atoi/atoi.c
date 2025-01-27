#include <stdio.h>
int whitespace(const char* str, int* ptr_i)
{
    int i = 0; 
    int sign = 1;
 while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
    {
        i++;
    }
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }
    *ptr_i = i;
    return sign;
}
int	ft_atoi(const char *str)
{
    int result = 0;
   
    int i = 0;
   
    int sign = whitespace(str, &i);
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10;
        result += str[i] - '0';
        i++;
    }
    return result * sign;
}
int main ()
{
    char str[] = "    -+-+-2345as";
   int number =  ft_atoi(str);
   printf("%d\n", number);
}