#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
// void print_char(int i)
// {
//     if(i < 9)
//     {
//      ft_putchar(i % 10 + '0');
//     }
//     else if(i > 9)
//     {
//         print_char(i / 10 );
//         ft_putchar(i % 10 + '0');
//     }
// }
int main (int argc, char**av)
{
    int num = atoi(av[1]);
    int i = 2;
    int index = 0;
    if(num == 1)
    printf("%d", num);
    while(num != 1)
    {
        if(num % i == 0)
        {
            num /= i;
           // print_char(i); we are allowed to use printf , so this was just to practic
           printf("%d", i);
            if(num != 1)
            {
                printf("*");
            }
            
        }
        else{
            i++;
        }
    }
    printf("\n");
    //write(1, "\n", 1);
}