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
 void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*))
 {
    int i = 0;
    while(tab[i] != NULL)
    {
        int j =  0;
        while(tab[j + 1] != NULL)
        {
            if(cmp(tab[i], tab[j + 1]) > 0)
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
    ft_advanced_sort_string_tab(tab, &ft_strcmp);
    int k = 0;
    while(tab[k] != NULL)
    {
        printf("%s\n", tab[k]);
        k++;
    }
 }