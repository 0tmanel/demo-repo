#include <stdio.h>
 int ft_isalnum(int c)
 {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
 }
 /*int ft_isalnum(int c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}
*/
 int main ()
 {
    int c = 'k';
    printf("%d\n", ft_isalnum(c));
 }