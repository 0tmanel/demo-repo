#include <stdlib.h>
#include <stdio.h>
/*
int *ft_range(int min, int max)
{
    int* dup;
    if(min >= max)
    return NULL;
    dup = (int*) malloc((max - min) * sizeof(int));
   *dup = min;
    int* tem = dup;
 
    while (min < max)
    {
        *dup = min;
        dup++;
        min++;
    }
    return tem;
   

}
int main ()
{
    int min = 12;
    int max = 20;
    int *dup = ft_range(min, max);
    int i = 0;
    while ( *dup < max)
    {
        printf("%d ", *dup);
       *dup++;
    }
    
}*/
 int *ft_range(int min, int max)
 {
    int *range = malloc(max - min * sizeof(int));
    if(range == NULL)
    {
        return NULL;
    }
    if (min > max)
    {
        return NULL;
    }
    int  i = 0;
    while (min < max)
    {
        range[i] = min;
        min++;
        i++;
    }
    return range;

 }
int main ()
{
    int min = 2;
    int max = 9;
   int *range = ft_range(min, max);
   int i = 0;
   while (i < max - min)
   {
    printf("%d", range[i]);
    i++;
   }

}