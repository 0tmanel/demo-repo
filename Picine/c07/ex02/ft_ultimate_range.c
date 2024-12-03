#include <stdio.h>
#include <stdlib.h>

/*
int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
    return 0;
    }
    int size = max - min;

    *range = (int *) malloc(size * sizeof(int));
    if(*range == NULL)
    return -1;

    int i = 0;
    while (min < max)
    {
        (*range)[i] = min;
        min++;
        i++;
    }
    return size;

}
int main ()
{
    int min = 2;
    int max = 9;
    int* range;
    int size;

   size = ft_ultimate_range(&range, min, max);

    printf("%d", size);

}*/
/*• Create a function ft_ultimate_range which allocates and assigns an array of ints.
This int array should contain all values between min and max.
• Min included - max excluded.
• Here’s how it should be prototyped :
• The size of range should be returned (or -1 on error).
• If the value of min is greater or equal to max’s value,
range will point on NULL and it should return 0.*/
/*int ft_len(int *temp, int min, int max)
{
    int i = 0;
    while (*temp)
    {
        temp++;
        i++;
    }
    return i;
}
int ft_ultimate_range(int *range, int min, int max)
{
    if (min >= max)
    {
        range = NULL;
        return 0;
    }
    range = malloc(max - min * sizeof(int));
    if(range == NULL)
    {
        return 0;
    }
    int *temp = range;
    int i = 0;
    while (min < max)
    {
        range[i] = min;
        min++;
        i++;
    }
    int len = ft_len(range, min, max);
    return len;
}
int main()
{
    int min = 2;
    int max = 10;
    int *range;
    int size = ft_ultimate_range(range, min, max);
    printf("%d", size);
}*/

/*int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }
    int size = max - min;
    *range = (int*)malloc(size * sizeof(int));
    if(*range == NULL)
    {
        return -1;
    }
    
    int i = 0;
    while (min < max)
    {
        (*range)[i] = min;
        min++;
        i++;
    }
    
    return len;
}
int main()
{
    int min = 2;
    int max = 10;
    int *range;
    int size = ft_ultimate_range(&range, min, max);
    printf("%d", size);
}*/
int ft_len(int *range)
{
    int i = 0;
    while (*range)
    {
       range++;
        i++;
    }
    return i;
}
 int ft_ultimate_range(int **range, int min, int max)
 //When a function parameter is declared as int **range in C, 
 //it indicates that the parameter is a pointer to a pointer to an integer
 //plus when you have this pattern int **range or char , it might mean one of these:
 //An array of pointers to integers:
 //===\\int *arr[5];    An array of 5 integer pointers
//===\\int **range = arr;   range points to arr, which is an array of pointers to integers

 //A pointer to a single pointer to an integer:

 //===\\int x = 10;
//====\\int *p = &x;
//=====\\int **range = &p;    range is a pointer to p, which is a pointer to x
 //A pointer to a dynamically allocated array:
 /*void ft_funct(int **range) {
    *range = malloc(5 * sizeof(int));  // Allocate an array of 5 integers
}

int main() {
    int *arr = NULL;
    ft_funct(&arr);  // Pass the address of arr to modify it in the function
}
*/

 {
    
    int len = max - min;
    if(min > max || min == max)
    {
        *range = NULL;
        return 0;
    }
    int *arr = malloc(len * sizeof(int));
    if(arr == NULL)
    {
        return -1;
    }
    
    
    int i = 0;
    while (min < max)
    {
        arr[i] = min;
        min++; 
        i++;

    }
    *range = arr;
    int size = ft_len(*range);
    return size;

 }
 int main ()
 {
    int min = 2;
    int max = 9;
   
    int *range = NULL;
    
    int size = ft_ultimate_range(&range, min, max);
    printf("%d\n", size);
 }
 