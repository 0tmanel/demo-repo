#include <stdio.h>
int ft_len(char ** tab)
{
    int i = 0;
    while (tab[i])
    {
        i++;
    }
    return i;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0 && s2[i] != '\0')
    {    
        i++;
    }
    return s1[i] - s2[i];
}
void ft_swap(char **l1, char ** l2)
{
    char *tem = *l1;
    *l1 = *l2;
    *l2 = tem;
}
void ft_sort_string_tab(char **tab)
{
    int i = 0;
    int len = ft_len(tab);
   
   int l = 0;
        while (l < len )
        {
            i = 0;
            while (i < len - 1)
            {
            if(ft_strcmp(tab[i], tab[i + 1]) > 0)
            {
                ft_swap(&tab[i], &tab[i + 1]);
            }
            i++;
            }
            l++;
        }
        tab[len] = NULL;

}
int main ()
{
    char *tab[]= {"hello", "bool", "ana", "zomibie", "killingkdj"};
    ft_sort_string_tab(tab);
    int i = 0;
    int len = ft_len(tab);
    while (i < len)
    {
        printf("%s\n", tab[i]);
        i++;
    }
} 