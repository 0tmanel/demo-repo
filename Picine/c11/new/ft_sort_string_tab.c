 #include <stdlib.h>
 #include <stdio.h>
int ft_strcmp(char *s1, char *s2)
 {
 int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' )
    {
        i++;
    }
    return s1[i] - s2[i];
}
void ft_swap(char **a, char **b)
{
    char *t;
    t = *a;
    *a = *b;
    *b = t;
}
 void ft_sort_string_tab(char **tab)
 {
    int i = 0;
    while(tab[i] != NULL)
    {
        int j = i + 1;
        while(tab[j] != NULL)
        {
            if(ft_strcmp(tab[i], tab[j]) > 0)
            {
                ft_swap(&tab[i], &tab[j]);
            }
            j++;
        }
        i++;
    }
 }
 int main ()
 {
    char *tab[] = {"hello", "world", "my name", "is otman", NULL};
    ft_sort_string_tab(tab);
    int k = 0;
    while(tab[k] != NULL)
    {
        printf("%s\n", tab[k]);
        k++;
    }
 }