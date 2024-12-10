#include <unistd.h>
#include <stdio.h>
/*
void ft_ft(int *nbr)
{
     *nbr = 42;
        printf("%d", *nbr);
    

}
int main ()
{ 
   
   int nb;
    ft_ft(&nb);

}*/

 void ft_ft(int *nbr)
 {
 *nbr = 42;
 }

int main ()
{
   int nbr = 10;

   
   printf("%d\n", nbr);
   ft_ft(&nbr);//pass by reference so anythinge happened in the called function 
                //affect the original value
 printf("%d\n", nbr);
   
}
