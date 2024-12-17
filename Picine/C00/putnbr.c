#include <unistd.h>
#include <limits.h>
/*
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

} */
 //void ft_putchar(char c)
 //{
  //  write(1, &c, 1);
 //}
void ft_putnbr(int nbr)
{
//In C, the data type that is always positive (or at least cannot 
//represent negative values) is unsigned types. Specifically, 
//unsigned data types are designed to only represent non-negative values 
//(i.e., values greater than or equal to zero).


   
    
    if(nbr < 0)
    {
     write(1, "-", 1);
    nbr = nbr * -1;
 //This technique works because the multiplication of any number by -1
 //reverses its sign. In mathematical terms, it's a reflection across 
 //the number line. Multiplying by -1 . −1 is a simple way to switch the sign
  //without needing to manually "flip" the number.
 // Alternatively, you could use abs() (from stdlib.h) for clarity:
//#include <stdlib.h>
//nbr = abs(nbr); but it is forbiden ;)
    }
    if(nbr <= 9)
    {
      // ft_putchar(nbr % 10 + '0');
      char i = nbr % 10 + '0';
      write(1, &i, 1);

    }
    if(nbr >= 9)
    {
        ft_putnbr(nbr / 10);
        //ft_putchar( nbr % 10 + '0');
        char i = nbr % 10 + '0';
      write(1, &i, 1);
//The recursive part of the function (ft_putnbr(nbr / 10)) 
//can be tricky to follow. You're recursively calling ft_putnbr() 
 //to handle all digits except the last one, which is then written with the
//line write(1, &i, 1);.

    }
   
    
}
int main ()
{
    ft_putnbr(-2147483646);
    write(1, "\n", 1);
    
    
}