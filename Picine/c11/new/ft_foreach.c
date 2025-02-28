  #include <unistd.h>
  void ft_putchar(char c)
  {
    write(1, &c, 1);
  }
void ft_putnbr(int nb)
  {
    long n = (long) nb;
    if(n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if(n < 9)
    {
        ft_putchar(n % 10 + '0');
    }
    
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
       
    }
  }
 void ft_foreach(int *tab, int length, void(*f)(int))
 {
    int i = 0;
    while (i < length)
    {
        f(tab[i]);
        i++;
    }

 }
 int main ()
 {
    int tab[] = {1, 2, 3, 4, 5};
    int length = 5;
    ft_foreach(tab, length, &ft_putnbr);
    write(1, "\n", 1);
 }