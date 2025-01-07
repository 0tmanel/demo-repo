 #include <stdio.h>
 //The square of a number is the value that is obtained when we multiply the number by itself, while the square root of a number is obtained by finding a number that when squared gives the original number.
 // If 'a' is the square root of 'b', it means that a × a = b. The square of any number is always a positive number, so every number has two square roots, one of a positive value, and one of a negative value. For example, both 2 and -2 are square roots of 4. However, in most places, only the positive value is written as the square root of a number.
 //The square root of a number is the value of power 1/2 of that number. 
 int ft_sqrt(int nb)
 {
    long n = nb;
    if(n < 0)
        return 0;
    if(n == 1)
    return 1;
//Why Use long Instead of int?
//In most systems, a long is typically a 64-bit signed integer, which has a much larger range (usually from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 on a 64-bit system). This gives you a much larger range to handle larger numbers before encountering overflow.
//Prevent Overflow When Squaring i:
//The main issue is the comparison i * i == n inside your while loop. If i is too large (close to the upper limit of int), squaring it (i * i) could exceed the maximum value that int can hold, causing an overflow. By using long for both n and i, you ensure that the multiplication i * i doesn’t overflow.
    long i = 2;
    while (i <= n)
    {
        if(i * i == n)
        {
            return i;
        }
        i++;
    }
    return 0;
    
 }
 //there four ways to find the square root of a number but here we will emplement just the simple one , we start a loop from 0 : i = 0, and multiply i with i and check if the result equal the number if it is , then i is the perfect square of the number 
 int    main(void)
{
	printf("sqrt of %d is %d\n", -2282, ft_sqrt(-2282));
	printf("sqrt of %d is %d\n", 0, ft_sqrt(0));
	printf("sqrt of %d is %d\n", 1, ft_sqrt(1));
	printf("sqrt of %d is %d\n", 2, ft_sqrt(2));
	printf("sqrt of %d is %d\n", 1640045925, ft_sqrt(1640045925));
	printf("sqrt of %d is %d\n", 2147395600, ft_sqrt(2147395600));
	printf("sqrt of %d is %d\n", 2147483646, ft_sqrt(2147483646));
	printf("sqrt of %d is %d\n", 20286016, ft_sqrt(20286016));
	printf("sqrt of %d is %d\n", 1120795600, ft_sqrt(1120795600));
	printf("sqrt of %d is %d\n", 484440100, ft_sqrt(484440100));
	printf("sqrt of %d is %d\n", 1046643418, ft_sqrt(1046643418));
	printf("sqrt of %d is %d\n", 1944104464, ft_sqrt(1944104464));
	printf("sqrt of %d is %d\n", 231739964, ft_sqrt(231739964));
	printf("sqrt of %d is %d\n", 1454436, ft_sqrt(1454436));
	printf("sqrt of %d is %d\n", 1411303165, ft_sqrt(1411303165));
	printf("sqrt of %d is %d\n", 259564321, ft_sqrt(259564321));
	printf("sqrt of %d is %d\n", 416153106, ft_sqrt(416153106));
        return (0);
}
 //An irrational number is a type of real number that cannot be expressed as a simple fraction, i.e., it cannot be written as the ratio of two integers. In other words, an irrational number is a number that, when written as a decimal, has a non-repeating, non-terminating expansion.

//For example:

//The square root of 2 (√2) is irrational because it cannot be expressed as a fraction, and its decimal expansion is approximately 1.414213562..., which goes on forever without repeating.
//The number π (pi) is irrational because it cannot be written as a fraction, and its decimal expansion (3.141592653...) is infinite and non-repeating.
//e (Euler's number), which is roughly 2.718, is also irrational for the same reason.