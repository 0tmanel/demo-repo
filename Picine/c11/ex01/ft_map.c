#include <stdio.h>
#include <stdlib.h>
int ft_malloc(int n)
{
   return n;
}
int *ft_map(int *tab, int length, int(*f)(int))
{
    int *array = malloc(length * sizeof(int));
    if(array == NULL)
    return NULL;
    int i = 0;
    while (i < length )
    {
        array[i] = f(tab[i]);
        i++;
    }
    return array;

}
int main ()
{
    int tab[] = {1, 2, 3, 4, 5};
    int len = sizeof(tab) / sizeof(tab[0]);
    int* result = ft_map(tab, len, &ft_malloc);
    int  i = 0;
    while (i < len)
    {
    printf("%d", result[i]);
    i++;
    }
    free(result);
}