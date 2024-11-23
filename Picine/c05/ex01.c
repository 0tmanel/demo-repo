#include <stdio.h>
int ft_recursive_factorial(int nb)
{
    if(nb == 0)
    {
        return 1;
    }else

    return nb * ft_recursive_factorial(nb - 1);
       
    
}
int main ()
{
     int nb = 3;
    int result = ft_recursive_factorial(nb);
    printf("%d", result);
}