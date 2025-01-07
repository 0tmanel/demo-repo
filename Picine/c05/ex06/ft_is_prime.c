//A prime number is a number greater than 1 that has no divisors other than 1 and itself. So, you can check if a number is divisible by any number between 2 and n−1. 
//If it is divisible by any of them, it's not prime.

//When we say that one number is divisible by another, it means that when you divide the first number by the second number, there is no remainder
#include <stdio.h>
int ft_is_prime(int nb)
{
    if(nb == 0 || nb == 1)
    return 0;
    long n = nb;
    long i = 2;


//Current approach (using square root): You only check up to sqrt(nb). This significantly reduces the number of iterations, especially for larger values. For example, for nb = 10,000, you only need to check up to 100 (since sqrt(10,000) = 100), which is a big reduction in the number of checks.
 //inefficient approach: You check all numbers from 2 to nb-1. For larger values of nb, this becomes computationally expensive (for example, checking all numbers up to 10,000 for nb = 10,000). /*while (i < n)*
    while (i * i <= n)
    {
        if(n % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main ()
{
    
   int number = ft_is_prime(14);
    printf("%d\n", number);
    //here is some prime numbers to test : 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71
    //amd here is some non prime numbers to test : 0,1,4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28
}