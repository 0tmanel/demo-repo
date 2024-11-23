#include <stdio.h>
int ft_sqrt(int nb)
{
    int gues;
    long index ; 
    long b = nb;

    int result;
    if(b <= 0)
    return 0;
    if(b == 1)
    return 1;
   
        index = 2;
        if(2  < b)
        {
            while (index * index <= b)
            {
                if(index * index == b)
                {
                    return index;
                }
                index++;
            }
        }
        return 0;
      

}
int main ()
{
    int nb = 16;
    int result = ft_sqrt(nb);
     printf("%d", result);
}