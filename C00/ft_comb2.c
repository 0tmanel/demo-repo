#include <unistd.h> 
void ft_putchar(char c)
{
     write(1, &c, 1);
}
void print_digit(char n)
{
     ft_putchar(n / 10 + '0');
     ft_putchar(n % 10 + '0');
}
void ft_print_comb2(void)
{
     int a = 0;
     int b = 0;
     while (a <= 99)
     {
          b = a + 1;
          while (b <= 99)
          {
               print_digit(a);
               ft_putchar(' ');
               print_digit(b);
               if(a != 98)
               {
                    ft_putchar(',');
                   ft_putchar(' ');
               }
               b++;

          }
          a++;
     }

}
int main ()
{
     ft_print_comb2();
}