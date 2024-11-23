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
    unsigned int i = 0;
    while (s1[i] == s2[i] && s1[i]!= 0)
    {    
        i++;
    }
    return s1[i] - s2[i];

}
void ft_swap(char **l1, char **l2)
{
    char *tem = *l1;
    *l1 = *l2;
    *l2 = tem;
}
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char*, char*))
{
    int i = 0;
    int len = ft_len(tab);
   
   int l = 0;
        while (l < len - 1)
        {
            i = 0;
            while (i < len - 1)
            {/*tab[i + 1] check if the first element is true and before the null */
            if(tab[i + 1] && cmp(tab[i], tab[i + 1]) > 0)//if the comparion was jsut one letter we will delete ft_strcmp
            {
                ft_swap(&tab[i], &tab[i + 1]);//else if the comparision is the whole character of the words we keep it 
            }
            i++;
            }
            l++;
        }
        tab[len] = NULL;
}
int main ()
{
    char *tab[]= {"hello", "bool", "ana"};
    ft_advanced_sort_string_tab(tab, &ft_strcmp);
    int i = 0;
    int len = ft_len(tab);
    while (i < len)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}