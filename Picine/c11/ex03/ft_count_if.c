#include <stdio.h>
int ft_f(char* s)
{
  if(s[0] != '\0')
  {
    return 1;
  }
  else
  return 0;
    
}
int ft_count_if(char**tab, int length, int (*f)(char*))
{
    int i = 0;
 
    int elements = 0 ;
    while (i < length)
    {
        elements += f(tab[i]);
        i++;
    }
    return elements;
}
int main ()
{
    char *tab[] = {"hello", "k", "how"};
    int len = 3;
    printf("%d", ft_count_if(tab, len, &ft_f));
}