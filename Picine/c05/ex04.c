#include <stdio.h>
int ft_fibonacci(int index)
{
    int F = 0;
    int F2 = 1;
  
    if(index == 0)
        return 0;
    if(index == 1)
    return 1;
    else
    return ft_fibonacci(index - 1) + ft_fibonacci(index  - 2);
  
    

}
int main ()
{
    int index = 3;
    int result = ft_fibonacci(index);
    printf("%d", result);
}