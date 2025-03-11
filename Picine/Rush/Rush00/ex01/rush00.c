#include "ft_putchar.c"

void print_row(int x, char first, char middle, char last)
{
    int i;

    if (x <= 0)
        return;
    ft_putchar(first);
    i = 2;
    while (i < x)
    {
        ft_putchar(middle);
        i++;
    }
    if (x > 1)
        ft_putchar(last);
    ft_putchar('\n');
}

void print_column(int x, int y)
{
    int i, j;

    i = 2;
    while ( i < y)
    {
        ft_putchar('*');
        j = 2;
        while( j < x)
        {
            ft_putchar(' ');
            j++;
        }
        if (x > 1)
            ft_putchar('*');
        ft_putchar('\n');
        i++;
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0)
        return;
    print_row(x, '/', '*', '\\'); // Top row
    print_column(x, y);          // Middle part
    if (y > 1)
        print_row(x, '\\', '*', '/'); // Bottom row
}
/*
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
void width(int x)
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
   width(x);
   break;
   }
        ft_putchar('|');
      space(x);
        ft_putchar('\n');
    
    i++;
   }
        
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
    width(x);
   length(x, y);
    }
    else {

   width(x);
   length_more(x, y);
   width(x);
    }
   
}
*/