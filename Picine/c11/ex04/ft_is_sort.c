#include <stdio.h>
int ft_sorting(int num1, int num2)
{   
     if(num1 < num2)
    {
      return (-1);
    } if (num1 == num2)
    {
      return 0;
    }else
    return 1; 
 
}
int ft_is_sort(int tab[], int length, int (*f)(int, int))
{
    int i = 0;
    int j ;
    while (i < length - 1)
    {
      j = i + 1;
    if(f(tab[i], tab[j]) >= 0)
    {
      return 0;
    }
   
    i++;
    }
   return 1;
}
int main ()
{
    int tab[] = {1, 2, 3, 4};
    int length = 4;
   int result =  ft_is_sort(tab, length, ft_sorting);
   printf("%d", result);

    
}