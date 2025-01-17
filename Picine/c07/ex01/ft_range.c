#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int* dup;
    if(min >= max)
    return NULL;
    dup = (int*) malloc((max - min) * sizeof(int));
  
    int* tem = dup;
    //This assigns the address stored in dup (i.e., the pointer to the allocated memory) to tem.
   //At this point, both dup and tem are pointing to the same memory block. Essentially, both dup and tem will have the same address after this assignment, and they both refer to the same allocated memory.
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
    
    while (*dup)
    {
        printf("%d\n", *dup);
       dup++;
    }
    free(dup);
    
}
/*
 int *ft_range(int min, int max)
 {
    int len = max - min;
    int *arr = malloc((len ) * sizeof(int));
    if(arr == NULL)
    {
        return NULL;
    }
    if (min >= max)
    {
        return NULL;
    }
    int  i = 0;
    while(min < max)
    {
        arr[i] = min;
        i++;
        min++;
        //if you used arr++ and returned arr it will not work 
    }
    return arr;
 }
 int main()
 {
   
    int *arr = ft_range(2, 9);
    while (*arr)
    {
        printf("%d\n", *arr);
        arr++;
    }
 }*/