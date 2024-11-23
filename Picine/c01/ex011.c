#include <unistd.h>
#include <stdio.h>
void ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
    printf("%d", *********nbr);

}
int main ()
{
    int p;
   int *pp = &p;
   int **p_2 = &pp;
   int ***p_3 = &p_2;
   int ****p_4 = &p_3;
   int *****p_5 = &p_4;
   int ******p_6 = &p_5;
   int *******p_7 = &p_6;
   int ********p_8 = &p_7;
   int *********p_9 = &p_8;
   
    ft_ultimate_ft(p_9);
}