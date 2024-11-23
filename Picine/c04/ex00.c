
#include <unistd.h>
void ft_putnbr(int nb)
{
    int digit;
    long long nb; 
   
    if(nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
   
     if(nb < 9)
    {
        digit = nb % 10 + '0';
        write(1, &digit, 1);
    }
    if ( nb > 9)
    {
        ft_putnbr(nb / 10);
        digit = nb % 10 + '0';
        write(1, &digit, 1);
    }

}
int main ()
{
    int nb = 42;
    ft_putnbr(42);
}