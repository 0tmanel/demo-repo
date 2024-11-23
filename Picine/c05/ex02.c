#include <stdio.h>
int ft_iterative_power(int nb, int power)
{
   int result = 1;
    
    while (power >= 1 )
    {
        result *= nb ;
        power--;
    }
    return result;

}
int main ()
{
    int nb = 3;
    int power = 4;
    int result = ft_iterative_power(nb, power);
    printf("%d", result);
}