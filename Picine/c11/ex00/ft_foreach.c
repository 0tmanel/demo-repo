#include <stdio.h>
int ft_putnbr(int n)
{
    printf("%d", n);
}

void ft_foreach(int *tab, int length, void(*f)(int)) //in the sunbject this function is the only one needed
{
    int i = 0;
    while (i <= length - 1)
    {
        f(tab[i]);
        i++;
    }

}
int main ()
{
    int tab[] = {1, 2, 3, 4, 5};
    int len = 5;
    ft_foreach(tab, len, &ft_putnbr);
}