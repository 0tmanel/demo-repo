//The bzero function is used to set a block of memory to zero. It is similar to memset but only sets bytes to 0.
#include <stdio.h>
//#include <string.h>

void ft_bzero(void *s, size_t n)
{
    if(n == 0)
    return;
    unsigned char* str = (unsigned char*)s;
    size_t i = 0;
    while(i < n)
    {
        str[i] = 0;
        i++;
    }
}

int main ()
{
    char str[] = "hello wolde how are you";
    ft_bzero(str + 5, 5);
    printf("%s\n", str);
    
}