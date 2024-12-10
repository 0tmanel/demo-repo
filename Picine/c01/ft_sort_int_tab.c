#include <stdio.h>
 void ft_sort_int_tab(int *tab, int size)
 {
    int i = 0;
    int j;
    while (i < size  )
    {
        j = 0;
        while (j < size)
// if you used j < size you need also use the same 
 //structure in the outer loop (i < size), there is also the other way 
 // (j <= size - 1) , note, the structure that you did 
 //in the inner loop it must be in the outer loop
        {
            if(tab[j] > tab[j + 1])
            {
            int temp = tab[j];
            tab[j] = tab[j + 1];
            tab[j+1] = temp;
            }
            j++;
        }
        i++;
    }

 }
int main ()
{
    int tab[] = {6, 5, 4, 3, 2, 1};
    int size = 6;
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%d", tab[i]);
        i++;
    }
    printf("\n");
}