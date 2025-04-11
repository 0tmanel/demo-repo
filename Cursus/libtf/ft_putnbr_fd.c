#include <limits.h>
#include <unistd.h>
void ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
void ft_putnbr(int n, int fd)
{
    long long nb  = n;
    // Base case: handle 0 directly
    if (nb == 0)
    {
        ft_putchar('0', fd);
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-', fd);
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10, fd);
    }
    ft_putchar(nb % 10 + '0', fd);
}