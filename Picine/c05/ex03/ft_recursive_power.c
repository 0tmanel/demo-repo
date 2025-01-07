#include <stdio.h>
//A function f1 is also recursive if it calls a function f2, which under some circumstances calls f1, creating a cycle in the sequence of calls. The ability to invoke itself enables a recursive function to be repeated with different parameter values. You can use recursion as an alterna- tive to iteration (looping).
int ft_recursive_power(int nb, int power)
{
    if(power < 0)
    return 0;
    if(power == 0)
    {
        return 1;
    }
    
    return nb * ft_recursive_power(nb, power - 1);
//The key in any recursive function is the BASE CASE, without which the recursion will go on until it overflows the stack. so the base case here is if power == 0;
}
int main ()
{
    int numb = ft_recursive_power(2, 5);
    printf("%d\n", numb);
}