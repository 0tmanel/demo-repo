#include <stdio.h>
int ft_is_prime(int nb)
{
   int index = 2;
   if(nb < 2)
   return 0;
   if(nb == 2)
   return 1;
  
    if(nb > 2)
   {
    while (index * index <= nb)
    {
        if (nb % index == 0)
        {
            return 0;
        } 
        index++;
    }
   }
        return 1;
   
}
int main ()
{
    
    int nb = 2;
    int result = ft_is_prime(nb);
     printf("%d", result);
}