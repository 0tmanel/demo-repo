//A prime number is a number greater than 1 that has no divisors other than 1 and itself. So, you can check if a number is divisible by any number between 2 and n−1. 
//If it is divisible by any of them, it's not prime.

//When we say that one number is divisible by another, it means that when you divide the first number by the second number, there is no remainder
#include <stdio.h>
int ft_is_prime(int nb)
{
   if (nb < 2) return 0;  
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

/*
 the function above is correct, but we can make it faster by:

Checking 2 separately (since it's the only even prime).

Skipping even numbers in the loop (no need to check them).
int ft_is_prime(int nb)
{
    if (nb < 2) return 0;  
    if (nb == 2) return 1;  
    if (nb % 2 == 0) return 0;  // Eliminate even numbers early

    int i = 3;
    while (i * i <= nb)
    {
        if (nb % i == 0)
        {
            return 0;
        }
        i += 2;  // Skip even numbers, check only odd numbers
    }

    return 1;
}
*/
int main ()
{
    
  printf("this is prime numbers\n");
    printf("%d ", ft_is_prime(17));
    printf("%d ", ft_is_prime(19));
    printf("%d ", ft_is_prime(23));
    printf("%d ", ft_is_prime(29));
    printf("%d ", ft_is_prime(13));
    printf("%d ", ft_is_prime(11));
    printf("%d ", ft_is_prime(7));
    printf("%d ", ft_is_prime(5));
    printf("%d ", ft_is_prime(3));
    printf("%d\n", ft_is_prime(2));
    printf("this is non-prime numbers\n");
    printf("%d  ", ft_is_prime(4));
    printf("%d  ", ft_is_prime(6));
    printf("%d  ", ft_is_prime(8));
    printf("%d  ", ft_is_prime(9));
    printf("%d  ", ft_is_prime(10));
    printf("%d  ", ft_is_prime(12));
    printf("%d  ", ft_is_prime(14));
    printf("%d  ", ft_is_prime(15));
    printf("%d  ", ft_is_prime(16));
    printf("%d\n", ft_is_prime(18));
    //here is some prime numbers to test : 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71
    //amd here is some non prime numbers to test : 0,1,4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28
}
// To check if a number is prime, you want to ensure that it is only divisible by 1 and itself, and not by any other numbers in between. The more efficient approach is to check for divisibility starting from 2 up to the square root of the number (because if a number is divisible by any number larger than its square root, the other divisor will necessarily be smaller than the square root).
//If a number is even and greater than 2, it is not prime.

//2 is the only even prime number.

//All other prime numbers are odd.