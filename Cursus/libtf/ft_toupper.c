#include <stdio.h>
int ft_toupper(int c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c ;
}
int main ()
 {
    
    printf("%c\n", ft_toupper('k'));
 }