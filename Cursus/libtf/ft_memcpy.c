#include <string.h>
#include <stdio.h>
//The memcpy() function in C and C++ is used to copy a block of memory from one location to another. Unlike other copy functions, the memcpy function copies the specified number of bytes from one memory location to the other memory location regardless of the type of data stored.
//Important Points about memcpy()
//1: memcpy() doesn’t check for overflow or \0.
//2: memcpy() leads to undefined behaviour when source and destination addresses overlap.
void* ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char* ptr = ( unsigned char*)dest;
    const unsigned char* ptr2 = (const unsigned char*)src;
    size_t i = 0;
    while(i < n)
    {
        ptr[i] = ptr2[i];
        i++; 
    }
    return dest;

}

int main ()
{
    char dest[] = "my name is Khalid";
   const char src[] = "nise to meet you Otman";
    char * string =  ft_memcpy(dest , src, sizeof(src));
    printf("%s\n", dest);
}