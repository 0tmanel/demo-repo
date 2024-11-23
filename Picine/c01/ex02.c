#include <unistd.h>
#include <stdio.h>
void ft_swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    printf("the value of a is %d\n", *a);
    printf("the value of b is %d", *b);


}
int main ()
{
    int a, b;
    a = 23;
    b = 45;
    ft_swap(&a, &b);
     
}