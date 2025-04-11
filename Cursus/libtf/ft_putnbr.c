#include <limits.h>
#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int n)
{
    long long nb  = n;
    // Base case: handle 0 directly
    if (nb == 0)
    {
        ft_putchar('0');
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
    // if (nb <= 9)
    // {
    //     ft_putchar(nb % 10 + '0');
    // }
    // if (nb > 9)
    // {
    //     ft_putnbr(nb / 10);
    //    ft_putchar(nb % 10 + '0');
    // }
}
int main()
{
    ft_putnbr(INT_MAX);
    write(1, "\n", 1);
}