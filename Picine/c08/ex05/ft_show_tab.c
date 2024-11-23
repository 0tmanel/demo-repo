#include "ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>

void ft_show_tab(struct s_stock_str *par)
{
    while (par->str)
    {
        printf("%s\n", par->str);
        printf("%d\n", par->size);
        printf("%s\n", par->copy);
        par++;
    }
}
   
