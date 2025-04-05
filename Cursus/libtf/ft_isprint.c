#include <stdio.h>
int ft_isprint(int c)
{
    return(c >= 32 && c <= 126);
}
int main ()
 {
    
    printf("%d\n", ft_isprint(128));
 }