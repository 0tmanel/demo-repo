  #include "ft_stock_str.h"
  #include "../ex04/ft_strs_to_tabs.c"
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
  void ft_putstr(char *str)
  {
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
  }
  void ft_show_tab(struct s_stock_str *par)
  {
    int i = 1;
    while(par[i].str != NULL)
    {
        ft_putstr(par[i].str);
       ft_putstr("\n");
        ft_putnbr(par[i].size);
        ft_putstr("\n");
        ft_putstr(par[i].copy);
         ft_putstr("\n");
        i++;
    }
  }
  int main (int ac, char **av)
  {
   
    ft_show_tab(ft_strs_to_tab(ac, av));
  }