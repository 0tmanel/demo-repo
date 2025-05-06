#include <stdio.h>
// arr[] and *arr are equivalent in function parameters — they both mean "pointer to int".
void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    while (i < size)
    {
        int j = i + 1;;
        while(j < size)
        {
            if(tab[i] > tab[j])
            {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
    int k = 0;
    // while(k < size)
    // {
    //     printf("%d\n", tab[k]);
    //     k++;
    // }
}
int main ()
{
    int array[] = {5, 4, 3, 2, 1};
    int size  = 5;
    sort_int_tab(array, size);
    int k = 0;
    while(k < size)
    {
        printf("%d\n", array[k]);
        k++;
    }
}