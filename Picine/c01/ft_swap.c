#include <unistd.h>
#include <stdio.h>
/*
void ft_swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    printf("the value of a is %d\n", *a);
    printf("the value of b is %d", *b);


}
int main ()
{
    int a, b;
    a = 23;
    b = 45;
    ft_swap(&a, &b);
     
}*/

 void ft_swap(int *a, int *b)//The asterisk (*) indicates that a is not an integer
                           // itself, but a pointer that stores the memory address of an integer.

 {
    int temp = *a;
    //You use a temporary variable temp to hold the value of *a, so that 
    //you don't lose the original value of *a when you overwrite it with *b. 
    *a = *b;
    *b = temp;

    /*In-place swapping :

Another way to swap values without a temporary variable is to use 
addition and subtraction:

void ft_swap(int *a, int *b) {
    if (a != b) {  // Same check as before
        *a = *a + *b;  // a becomes the sum of a and b
        *b = *a - *b;  // b becomes the original value of a
        *a = *a - *b;  // a becomes the original value of b
    }
}
This method uses arithmetic to perform the swap but has the disadvantage
 of potentially causing overflow if the integers are too large 
 (e.g., when a and b are near the limits of the integer range).*/

 }
int main ()
{
    int a = 9;
    int b = 8;
    printf("%d  %d\n", a, b);
    ft_swap(&a, &b);
     printf("%d  %d\n", a, b);
}
