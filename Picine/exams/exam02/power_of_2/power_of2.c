#include <stdio.h>
int	    is_power_of_2(unsigned int n)
{
    if(!(n & (n - 1)))//When you subtract 1 from a power of 2, you flip all the bits after the first 1.

    //For example, for n = 8 (1000 in binary):
      //n - 1 = 7 (0111 in binary)
    //(n & (n - 1)) = (1000 & 0111) = 0000 → This equals 0.

    {
        return 1;
    }
    return 0;
}
int main ()
{
    // is 2 8 32 128, 1024
    //not 3 10 25 60 77
    int bolen = is_power_of_2(10);
    printf("%d\n", bolen);
}