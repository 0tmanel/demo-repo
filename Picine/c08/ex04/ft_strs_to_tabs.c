#include "ft_stock_str.h"
#include <stdlib.h>
#include <string.h>
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *strs;

    int i = 0;
    int j = 0;
    char *str;
    char *copy;
    int size;
    strs = malloc(ac + 1 * sizeof(t_stock_str));
    if(strs == NULL)
    return NULL;
    while (i < ac)
    {
       
       while (av[i] != '\0')
       {
       i++;
       }
       size = i;

    strs[i].str = malloc(size  + 1);
    strs[i].copy = malloc(size + 1);
    if(strs[i].str == NULL || strs[i].copy == NULL)
    {
        int k = 0;
        while (k < i)
        {
           free(strs[k].str);
           free(strs[k].copy);
           k++;
        }
        free(strs);
    return NULL;
    }
        j = 0;
        while (j < size)
        {

             strs[i].str[j] = av[i][j]; 
             strs[i].copy[j]  = av[i][j];
            j++;
        }
        strs[i].str[size] = '\0';
        strs[i].copy[size] = '\0';
        strs[i].size = size;
        i++;
    }
    strs[ac].str = NULL;
   
        return strs;

}
int main(int ac, char **av)
{
    ft_strs_to_tab(ac, av);
    return 0;
}