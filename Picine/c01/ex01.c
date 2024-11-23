#include <unistd.h>
#include <stdio.h>
void ft_ft(int *nbr)
{
     *nbr = 42;
        printf("%d", *nbr);
    

}
int main ()
{ 
   
   int nb;
    ft_ft(&nb);

}
