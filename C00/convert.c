#include <unistd.h>
#include <stdio.h>
int main ()
{
    int i = 40;
  
    int count = 0;
    
    do {
        i /= 10;
        count++;

    } while (i > 0);
   printf("the number of digits is %d ", count);
   
}