#include "ft_putchar.c"
void space(int x)
{
     int j = 2;
        while (j < x)
        {
            ft_putchar(' ');
           
            j++;
        }   
}
void width(int x, int y)
{
     int i = 1;
    while (x >= i)
    {
        if(i == 1 || i == x)
        {
            ft_putchar('o');
        }
        else{
            ft_putchar('-');
        }
        i++;
    }
    ft_putchar('\n');
}
void length(int x, int y)
{
    int i = 2;
   while(y >= i)
   {
   if(i == y)
   {
   width(x, y);
   break;
   }
        ft_putchar('|');
      space(x);
        ft_putchar('\n');
    
    i++;
   }
        
}
void space_more(int x)
{
     int j = 2;
        while (j < x)
        {
            ft_putchar(' ');
           
            j++;
        }   
       
}
void width_more(int x, int y)
{
     int i = 1;
    while (x >= i)
    {
        if(i == 1 || i == x)
        {
            ft_putchar('o');
        }
        else{
            ft_putchar('-');
        }
        i++;
    }
    ft_putchar('\n');
}
void length_more(int x, int y)
{
    int i = 2;
   while(y > i)
   {
   
        ft_putchar('|');
       space(x);
       ft_putchar('|');
        ft_putchar('\n');
    
    i++;
   }
        
}
void rush(int x, int y)
{
    if(x == 0 && y == 0)
    {
        return;
    }
    if(x == 1 || y == 1)
    {
    width(x, y);
   length(x, y);
    }
    else {

   width_more(x, y);
   length_more(x, y);
   width_more(x, y);
    }
   
}