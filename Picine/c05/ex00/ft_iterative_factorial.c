 //The factorial of a non-negative integer 𝑛 , denoted as 𝑛!, is the product of all positive integers less than or equal to 𝑛.

 //In a factorial, the number itself (like the 5 in 5!) is not multiplied by itself. Instead, the factorial involves multiplying all the positive integers from that number down to 1.
#include <stdio.h>
 int ft_iterative_factorial(int nb)
 {
    int i = 1;
    int result = 1;
    if(nb < 0)
    {
        return 0;
        //because Factorial is not defined for negative integers
    }
    if(nb == 0 || nb == 1)
    {
        return 1;
    }

    while (i <= nb)
    {
        result  *= i;
        i++;
    }
    return result;
 }
 int main ()
 {
    int number = ft_iterative_factorial(5);
    printf("%d\n", number);
 }