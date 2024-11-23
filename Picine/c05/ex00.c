#include <stdio.h>
int ft_iterative_factorial(int nb)
{
    int tem = nb - 1;
    int i = 0;
    if(nb == 0 )
    return 0;
    while (tem > i)
    {
        nb = nb * tem;
        tem--;
    }
    return nb;
} 
int main ()
{
    int nb = 10;
    int result = ft_iterative_factorial(nb);
    printf("%d", result);
}