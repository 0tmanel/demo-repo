#include <stdio.h>
int ft_recursive_power(int nb, int power)
{
  
    if(power <= 0)
    return 1;
    else
    {
        return nb *ft_recursive_power(nb , power - 1);
    }
}
int main ()
{
    int nb = 3;
    int power = 4;
    int result = ft_recursive_power(nb, power);
    printf("%d", result);
}