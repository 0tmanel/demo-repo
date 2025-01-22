#include <unistd.h>
int main ()
{
    //you can do this 
    char a = 97;
    while (a <= 122)
    {
       if(a % 2 == 0)
        {
           a -= 32;
            write(1, &a, 1);
            a += 32;
            
        }else 
         write(1, &a, 1);
        
        a++;
    }
    write(1, "\n", 1);
    //or this 
    // write(1, "aBcDeFgHiJkLmNoPqRsTuVwXyZ", 26);
    // write(1, "\n", 1);

} 
/*
or this 
void ft_putchar(char c)
{
    write (1, &c, 1);
}
int main ()
{
    //you can do this 
    int a = 97;
    while (a <= 122)
    {
       if(a % 2 == 0)
        {
            ft_putchar(a - 32);
            
           
        }else 
         ft_putchar(a);
        
        a++;
    }
    write(1, "\n", 1);
}*/