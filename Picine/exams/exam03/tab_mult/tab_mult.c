#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
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
void ft_putnbr(int nb)
{
   if(nb <= 9)
   {
    ft_putchar(nb % 10 + '0');
   }
   if(nb > 9)
   {
    ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
   }
}
int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
void tab(char *str)
{
    int nbr = ft_atoi(str);
    int i = 1;
    while(i <= 9)
    {
      ft_putnbr(i);
        ft_putchar(' ');
        ft_putchar('x');
         ft_putchar(' ');
        if(str[1])
            ft_putstr(str);
        else{
        ft_putchar(str[0]);
        }
         ft_putchar(' ');
         ft_putchar('=');
          ft_putchar(' ');
        ft_putnbr(i * nbr);
         ft_putchar('\n');
         i++;
    }
}
int main(int argc, char **av)
{
    if (argc == 2)
    {
        tab(av[1]);
    }
    write(1, "\n", 1);
}