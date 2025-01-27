#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int main ()
{
    char a = 'z';
    while(a >= 'a')
    {
        if(a % 2 == 0)
        {
            ft_putchar(a);
        }
        else{

        ft_putchar(a - 32);
        }
        a--;
    }
    write (1, "\n", 1);
}