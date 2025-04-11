#include <stdio.h>
#include <stdlib.h>
int calcu_len(int n)
{
    int index = 0;
    while(n != 0)
    {
        n /= 10;
        index++;
    }
    return index;
}
char* ft_itoa(int n)
{
    int len = calcu_len(n);
    int is_negative = 0;
   if (n < 0) {
        is_negative = 1;
        n = -n; // work with the positive version for digit count
        len++;
    }
    char *string = malloc((len + 1) * sizeof(char));
    if(!string)
    return NULL;
  string[len] = '\0';
    int i = len - 1;
    while(n != 0)
    {
        string[i] = (n % 10) + '0';
         n /= 10;
        i--;
    }
    if(is_negative)
    {
        string[0] = '-';
    }
    return string;
}
int main ()
{
    printf("%s\n", ft_itoa(-45739));
}