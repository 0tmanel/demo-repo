#include <stdio.h>
 void ft_ultimate_div_mod(int *a, int *b)
 {
    //It's good practice to handle the possibility of division by zero. 
    //If *b is zero, attempting to divide by zero will cause undefined behavior.
    // You should check for this case and handle it properly
    int temp = *a;
    *a = temp / *b;
    *b = temp % *b;

 }
int main ()
{
    int a = 10;
    int  b = 5;
    ft_ultimate_div_mod(&a, &b);
    printf("%d  %d\n", a, b);
}