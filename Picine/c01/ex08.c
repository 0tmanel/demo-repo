#include <stdio.h>
#include <unistd.h>
void ft_rev_int_tab(int *tab, int size)
{
    int j = 0;
    int first = 0;
    int end = size - 1;
    int temp;
 
        while (first < end)
        {
            temp = tab[first];
            tab[first] = tab[end];
            tab[end] = temp;
        first++;
        end--;
        
        j++;
        }
}
int main ()
{
    int n = 5;
   int arr[] = {1, 2, 3, 4, 5};
   ft_rev_int_tab(arr, n);
   int i = 0;
   while (i < n)
   {
    printf("%d", arr[i]);
    i++;
   }
    

}