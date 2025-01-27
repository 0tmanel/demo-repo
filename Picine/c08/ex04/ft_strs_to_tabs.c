#include "ft_stock_str.h"
#include <stdlib.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 char *ft_strdup(char *src)
{
  int len = ft_strlen(src);
  char *strdup = malloc((len + 1) * sizeof(char));
  if (strdup == NULL)
  {
    return NULL;
  }

  int i = 0;
  while (src[i] != '\0')
  {
    strdup[i] = src[i];
    i++;
  }
  strdup[i] = '\0';

  return strdup;
}
 struct s_stock_str *ft_strs_to_tab(int ac, char **av)
 {
    int  i = 0;
    
    t_stock_str *string;
   
   string = malloc((ac + 1 )* sizeof(t_stock_str));
   if(!string)
   return NULL;
    while(i  < ac)
    {
       string[i].size =  ft_strlen(av[i]);
        string[i].str = av[i];
        string[i].copy = ft_strdup(av[i]);
        i++;
        }
        string[i].str = 0;
        string[i].copy = 0;
    
    return string;
 }

//When dealing with dynamic memory allocation in C, if you fail to clean up memory that was previously allocated before an error occurs, you'll create memory leaks. This happens because the memory is still allocated, but you lose the pointer to it, making it impossible to free that memory later.
//By freeing all previously allocated memory before returning, you're ensuring the program doesn't waste memory and the error handling is robust.