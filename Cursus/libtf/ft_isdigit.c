#include <stdio.h>
 int ft_isdigit(int c)
 {
    if(c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
 }
 int main ()
 {
    int c = '9';
    printf("%d\n", ft_isdigit(c));
 }