#include <stdio.h>
void ft_multi(void)
{
    int result;
    int result2;
    
    int i ;
    int j = 0;
    while (j <= 9)
    {
        i = 1;
    result2 = i * 10;
        while (i <= result2 )
        {
        result = j * i;
        printf("%d, ", result);
        i++;
        }
        printf("\n");
      j++;
    }

}
int main () 
{
ft_multi();
}