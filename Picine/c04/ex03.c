#include <stdio.h>
int ft_atoi_base(char *str, char *base)
{
    int result = 0;
    int conver = 0;
    int bas = 1;
    int i = 0;
    while (base[i] != '\0')
    {
        i++;
    }

    if (i == 8)
    {
        int n = 0;
        while (str[n] != 0)
        {
            n++;
        }
        int j = n - 1;
        while (j >= 0)
        {
            result = 0;
            result += str[j] - '0';
            conver += result * bas;
            bas *= 8;
            j--;
        }
        return conver;
    }
    if (i == 2)
    {
        int n = 0;
        while (str[n] != 0)
        {
            n++;
        }
        int j = n - 1;
        while (j >= 0)
        {
            result = 0;
            result += str[j] - '0';
            conver += result * bas;
            bas *= 2;
            j--;
        }
        return conver;
    }
    if (i == 16)
    {
        
            int n = 0;
            while (str[n] != 0)
            {
                n++;
            }
            int j = n - 1;
            while (j >= 0)
            {
                int k = 0;
                while (base[k] != 0)
                {
                    if (base[k] >= 65 && base[k] <= 70)
                        break;
                        k++;
                }
                if(str[j] >= 65 && str [j] <= 70)
                {
                    result = k;
                    conver += result * bas;
                    bas *= 16;
                }else if(str[j] >= '0' && str[j] <= '9')
                {
                    
                result = 0;
                result += str[j] - '0';
                conver += result * bas;
                bas *= 16;
                }
                j--;
            }
        return conver;
        }
     
}

int main()
{
    char str[] = "63";
    char base[] = "0123456789ABCDEF";
    int result = ft_atoi_base(str, base);
    printf("%d", result);
}