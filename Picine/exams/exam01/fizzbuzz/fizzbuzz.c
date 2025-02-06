#include <stdio.h>
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
void ft_fizzbuzz(void)
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0)
        {
            ft_putstr("fizz\n");
        }
        else if (i % 5 == 0)
        {
            ft_putstr("buzz\n");
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            ft_putstr("fizzbuzz\n");
        }
        else
        {
            if(i < 9)
            {
          ft_putchar( i % 10 + '0');
            }
          if(i > 9)
          {
             ft_putchar( i / 10 + '0');
              ft_putchar( i % 10 + '0');
              //i / 10 extracts the most significant digit (the "tens" place) of the number i.i % 10 extracts the least significant digit (the "ones" place) of the number i.
          }
            ft_putchar('\n');
        }
        i++;
    }
}
int main()
{
    ft_fizzbuzz();
}