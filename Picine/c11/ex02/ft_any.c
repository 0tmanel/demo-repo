#include <stdio.h>
#include <string.h>
int ft_patrn(char* s)
{
    int i = 0;
   
        if(strcmp(s ,"lk"))
        {
           return 1;
        }
        else
    return 0; 
}
int ft_any(char **tab, int(*f)(char*))
{
    int i = 0;
    int j = 0;
    int len = sizeof(tab) / sizeof(tab[0]);
    tab[len] = NULL;
    
    while (tab[i] != NULL)
    {
        if(f(tab[i]))
        {
            return 1;
        }
        else 
        i++;
    }
    
    return 0;
}
int main ()
{
    char* tab[] = {"hello", "hi", "goo"};

    int result = ft_any(tab, &ft_patrn);
    printf("%d", result);
}