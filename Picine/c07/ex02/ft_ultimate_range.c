#include <stdio.h>
#include <stdlib.h>
/*• Create a function ft_ultimate_range which allocates and assigns an array of ints.
This int array should contain all values between min and max.
• Min included - max excluded.
• Here’s how it should be prototyped :
• The size of range should be returned (or -1 on error).
• If the value of min is greater or equal to max’s value,
range will point on NULL and it should return 0.*/

/*


/****************************VERSION 1**************************** */
//HERE WE directly allocate memory into *range. This avoids the intermediate pointer arr and simplifies the code. It's more direct and efficient.
//i prefer this version
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
    //(int *) is used to cast the return value of malloc to the appropriate type, which is a pointer to an int (int*).

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
    int* range = NULL;

   int size = ft_ultimate_range(&range, min, max);

    printf("%d", size);

}*/
/**************************VERSION 2******************************** */

//HERE we allocate memory into a local pointer arr and then assign *range = arr at the end. This works fine, but it introduces an unnecessary extra pointer (arr) that you don’t need.
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
 /*
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
 void ft_funct(int **range) {
    *range = malloc(5 * sizeof(int));  // Allocate an array of 5 integers
}
int main() {
    int *arr = NULL;
    ft_funct(&arr);  // Pass the address of arr to modify it in the function
}
*/


 {
    
    int len = max - min;
    if(min >= max)
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
    
    return len;

 }
 int main ()
 {
    int min = 2;
    int max = 9;
   
    int *range = NULL;
    //Uninitialized pointers can lead to undefined behavior. If you declare a pointer but don't initialize it, it may point to some random memory address (often referred to as a "garbage value"). Dereferencing such a pointer or using it can lead to unpredictable results, crashes, or memory corruption.
    //By initializing range to NULL, you ensure that it starts with a known value. A NULL pointer is a valid state for a pointer and means that the pointer is not currently pointing to any valid memory location.
    
    int size = ft_ultimate_range(&range, min, max);
    printf("%d\n", size);
 }
 