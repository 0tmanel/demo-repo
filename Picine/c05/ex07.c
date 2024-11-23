#include <stdio.h>
int ft_prim(int nb);  
int ft_find_next_prime(int nb)
{
    int next = nb + 1;
    while (1)
    {
       if (ft_prim(next))
       {
            return next;
       }
        next++;
    }
}
int ft_prim(int nb)
{
    int index = 2;
    if(nb == 0)
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
     int nb = 7;
    int result = ft_find_next_prime(nb);
     printf("%d", result);
}