 #include <stdio.h>
 //any number raised to the power of 0 is 1
 int ft_iterative_power(int nb, int power)
 {
    if (power < 0)
    return 0;
    if(power == 0)
        return 1;
    int i = 1;
    int result = nb;
    while (i < power)
    {
        result *= nb;
        //power--;
        //you can decriment power but it is better to not change it and use i because power here represent an argument and we should not modify it. but in the recursive version we modify it , so it is based on you .
        i++;
    }
    return result;
 }
 //the compiler actually maintains a single system stack. Each time a call to a function occurs, all its parameters and local variables are pushed onto the stack along with the memory address of the calling statement. This address gives the computer the return point after execution of the function. Although mul- tiple copies of a function’s parameters may be saved on the stack, only one copy of the function body is in memory.
 int main ()
 {
    int numb = ft_iterative_power(5, 3);
    printf("%d\n", numb);
 }