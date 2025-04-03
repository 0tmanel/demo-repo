// To check if a number is prime, you want to ensure that it is only divisible by 1 and itself, and not by any other numbers in between. The more efficient approach is to check for divisibility starting from 2 up to the square root of the number (because if a number is divisible by any number larger than its square root, the other divisor will necessarily be smaller than the square root).
// If a number is even and greater than 2, it is not prime.

// 2 is the only even prime number.

// All other prime numbers are odd.
#include <stdlib.h>
#include <stdio.h>
int ft_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    int i = 2;
    while (i * i <= nb)
    {
        if (nb % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main(int argc, char **av)
{
    int num = atoi(av[1]);
    if (argc == 1 || num <= 0)
    {
        printf("0\n");
        return 0;
    }
    if (num < 2)
        return 0;
    int sum = 0;
    int i = 2;
    while (i <= num)
    {
        if (ft_is_prime(i))
        {
            sum += i;
        }
        i++;
    }
    printf("%d\n", sum);
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
/*
#include <unistd.h>

int  ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return(0);
}

void  ft_print_nbr(int n)
{
	if (n >= 10)
		ft_print_nbr(n / 10);
	n = (n % 10 + '0');
	write(1, &n, 1);
}

// since we are not dealing with any negatives,
// I made it an unsigned int 
unsigned int ft_atoi(char *s)
{
	int index = 0;
	unsigned int result = 0;

	while (ft_isspace(s[index]) && s[index])
		index++;
	if (s[index] == '-' || s[index] == '+')
	{
		if (s[index] == '-')
		{
			// if it is negative , just return the number zero
			result = 0;
			return (result);
		}
		index++; // otherwise increment over the + sign
	}
	while (s[index] && s[index] >= '0' && s[index] <= '9')
		result = s[index++] - '0' + (result * 10); // standard atoi converting a character to an int then * by 10 if there is more than 1
	return (result);
}

// this just checks if it is a prime number - 0 for false 1 for true
int ft_is_prime(int n)
{
	int index = 2; // we are setting this to 2 since a prime number has a factor or 1 and itsel... so wh can start dividing form 2 to see if it is prime

	while (index < n)
	{
		if (n % index == 0) // so if it is divisible by 2 (or any other increment of index (and has no remainder)) then it isn't prime  
			return(0); // so return false;.
		index++;
	} // it will break out of this loop when index is the same is n (the number we are checking)
	return (1); // and since it wasn't divisible by any other number , that means its only factors is 1 and itself. thus it is prime
}
//now we are going to add all the prime numbers of a number together
void	ft_add_prime(int n)
{
	int index = 2; 
	int sumof = 0;

	while (index <= n)
	{
		if (ft_is_prime(index)) // check if the current number index is prime
			sumof += index; //if it is just add it (we are adding up all the prime numbers together)
		index++;
	}
	ft_print_nbr(sumof); // print out the sum of all the prime numbers
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int av = ft_atoi(argv[1]); // change argv to an integer
		if (av == 0) // if it is 0 - just print out a zero and a newline
		{
			write(1, "0\n", 2);
			return (0);
		}
		ft_add_prime(av); // otherwise print out the sum of the prime numbers
	}
	else
		write(1, "0", 1); // if no arguments or too man arguments are added print out a zero
	write(1, "\n", 1); // and add a newline
	return (0);
}*/
