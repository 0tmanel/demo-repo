#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
   struct s_stock_str *tab;

   tab = ft_strs_to_tab(ac-1, av+1);
   if(tab != NULL)
   {
   ft_show_tab(tab);

   }
   
    return 0;
}
