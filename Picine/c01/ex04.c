#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;

}
int main ()
{
    int num = 42;
    int bnum = 4;
    int pdiv;
    int pmod;
     ft_div_mod(num, bnum, &pdiv, &pmod);
     printf("the value of the pointer div is %d\n", pdiv);
     printf("the reminder of the divesion is %d", pmod);

}