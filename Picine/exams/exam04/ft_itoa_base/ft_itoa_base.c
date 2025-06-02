#include <stdio.h>
#include <stdlib.h>
char* turn_base(int base)
{
    int i = 0;
    int j = 0;
    char *str = malloc(base);
    while(i < base)
    {
        if(i > 9)
        {
            str[i] = j  + 'A';
            j++;
        }else{
        str[i] = i + '0';
        }
        i++;
    }
    return str;
}
int calcu_hex(int value, int base)
{
    
    int index = 0;
    if(base == 10 && value < 0)
    {
        index++;
    }
    while(value != 0)
    {
        value /= base;
        index++;
    }
    return index;
}
void fill_str(char* str, int len, int value, char* base, int basei)
{
    int i = len;
    str[i--] = '\0';
    while(value != 0)
    {
        str[i--] = base[value % basei];
         str[i--] = base[value / basei];
        value /= basei;
    }
   if(basei == 10 && value < 0)
    {
        str[i] = '-';
    }
}
char	*ft_itoa_base(int value, int base)
{
    if(base < 2 || base > 16)
    {
        return NULL;
    }
    char * bse = turn_base(base);
    int len = calcu_hex(value, base);
    char* str = malloc((len + 1) * sizeof(char));
    fill_str(str, len, value, bse, base);
    return str;
}
int main()
{
    int value = 101010;
    int base = 10;
    char* str = ft_itoa_base(value, base);
    printf("%s\n", str);
}