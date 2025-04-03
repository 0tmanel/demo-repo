// atoi()-like functions, multiple consecutive signs (-+-, ++--, etc.) are not valid because the standard atoi() function in C only allows one sign (+ or -) at the beginning of the number. so we use only if condition to test if there is a - or +, but with non standard we use while to ignor multuple signs
#include <stdio.h>

int ft_atoi( char *str)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
           sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;
}
int main()
{
    char *str = "     -1234";
    int len = ft_atoi(str);
    printf("%d\n", len);
}