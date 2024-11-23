#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_hex(int b)
{
    char hex[] = "0123456789abcdef";
     ft_putchar(hex[b / 16 ]);
     ft_putchar(hex[b % 16]);
  
}
void ft_putstr_non_printable(char *str)
{

    int i = 0;
    while (str[i] != 0)
    {
        if(str[i] >= 32 && str[i] <= 126)
        {
        write(1, &str[i], 1);
        }else {

            ft_putchar('\\');
            ft_hex((unsigned char)str[i]);
        }
        i++;

    }
}
int main ()
{
    char str[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(str);
   
}