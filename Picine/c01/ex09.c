#include <stdio.h>
#include <unistd.h>
void ft_sort_int_tab(int *tab, int size)
{
    int first = 0;
    int i = 0;
    int tem;
    
    while (i < size - 1)
    {
       first = 0;
        while (first < size - 1)
        {
        if (tab[first] > tab[first + 1])
        {
            tem = tab[first];
            tab[first] = tab[first + 1];
            tab[first + 1] = tem;
        }
            first++;

        }
        i++;
    }

}
int main ()
{
    int tab[] = {2, 5, 4, 1, 3};
    int size = 5;
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%d", tab[i]);
        i++;
    }
}