#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
    write (1, &c, 1);
}
 void ft_print_comb2(void)
 {/*
    int i = 0;
    int j ;
    while (i  <= 98)
    {

        j =  1 + i;
        while ( j <= 99)
        {
            write (1, &"0123456789"[i / 10], 1);
            write (1, &"0123456789"[i % 10], 1);
            write(1, " ", 1);
            write (1, &"0123456789"[j / 10], 1);
            write (1, &"0123456789"[j % 10], 1);
            if(!(i == 98 && j == 99))
            {
                write(1, ", ", 2);
            }
            j++;
            
        }
        i++;
    }*/
   int i  = 00;// how this number is represented in memory
   //In C, when a number is written with a leading 
   //zero (like 00), it is interpreted as an octal 
   //(base 8) number, not a decimal (base 10) number. 
//The number 00 is an octal literal.
//In octal, 00 represents the value 0 in decimal.
   int j = 01;
   while (i <= 98)
   {
    j = i + 1;
    while (j <= 99)
    {
      ft_putchar(i / 10 + '0');//So, ft_putchar(i / 10 + '0') prints the first digit 
                             //(the tens place) of the integer i as a character.
      ft_putchar(i % 10 + '0');
       write (1, " ", 1);
      ft_putchar(j / 10 + '0');
      ft_putchar(j % 10 + '0');
       if(i != 98 || j != 99)
       {
        write(1, ", ", 2);
       }
       j++;
    }
    i++;
   }

 }
 int main ()
 {
    ft_print_comb2();
 }