 #include <stdio.h>
 //The Fibonacci sequence is defined such that each number is the sum of the two preceding ones. So:
//F(n)=F(n−1)+F(n−2)

//The base case in a Fibonacci sequence function is the simplest scenario where the function can directly return a result without needing further calculations. In the context of the Fibonacci sequence, the base cases correspond to the first two numbers in the sequence:

//F(0) = 0
//F(1) = 1
//These base cases are necessary to prevent the recursion (if you're using a recursive approach) from continuing indefinitely or to stop an iterative loop at the right starting point.
 int ft_fibonacci(int index)
 {
    if(index < 0)
    {
        return -1;
    }
    if (index == 0 || index == 1) 
    return index;

    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);

 }
 //when the calling functiion is the last statment in the function , it is called tail recursion
 int main ()
 {
   int numb = ft_fibonacci(9);
   printf("%d\n", numb);
 }