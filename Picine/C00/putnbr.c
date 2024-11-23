#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_putnbr(int n)
{
 long long nb;

 
   if(nb < 0)
   {
    ft_putchar('-');
   nb = -nb;
    
   }
   
    
    if(nb < 9)
    {
        ft_putchar(nb % 10 + '0');
        
    }
    if (nb > 9)
    {
        
        ft_putnbr(nb / 10 );
      
        ft_putchar( nb % 10 + '0');
    }
   
}
int main ()
{
   
    ft_putnbr(2147483648);

} 