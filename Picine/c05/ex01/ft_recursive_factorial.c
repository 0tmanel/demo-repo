 #include <stdio.h>
 //Some programming languages rely heavily on recursion, while others don’t even allow it. C falls somewhere in the middle: it allows recursion, but most C programmers don’t use it that often.

 //look more about recursion

 //A function is recursive if it calls itself. For example, the following function computes n! recursively, using the formula 
 //n! = n × (n – 1)!:
 int ft_recursive_factorial(int nb)
 {
    if(nb < 0)
    {
        return 0;
        //because Factorial is not defined for negative integers
    }
    if(nb == 0 || nb == 1)
    {
        return 1;
    }
    if(nb > 1)
    {
        return nb * ft_recursive_factorial(nb - 1);
    }
    return nb;
 }
 int main()
 {
    int numb = ft_recursive_factorial(6);
    printf("%d\n", numb);
 }
 //To see how recursion works, let’s trace the execution of the statement
//i = fact(3);
//Here’s what happens:
//fact(3) finds that 3 is not less than or equal to 1, so it calls fact(2), which finds that 2 is not less than or equal to 1, so it calls
//fact(1), which finds that 1 is less than or equal to 1, so it returns 1, causing fact(2) to return 2 × 1 = 2, causing
//fact(3) to return 3 × 2 = 6.

//Notice how the unfinished calls of fact “pile up” until fact is finally passed 1. At that point, the old calls of fact begin to “unwind” one by one, until the origi- nal call—fact(3)—finally returns with the answer, 6.
