#include <stdio.h>
void ft_ultumate_div_mod(int *a, int *b)
{
     int t = *a;
    *a = t / *b;
    *b =  t % *b;
}
int main ()
{
    
    int pdiv = 42;
    int pmod = 10;
     ft_ultumate_div_mod(&pdiv, &pmod);
     printf("the value of the pointer div is %d\n", pdiv);
     printf("the reminder of the divesion is %d", pmod);

}