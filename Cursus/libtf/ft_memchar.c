/*
​The memchr() function scans the initial n bytes of the memory area pointed to by s for the first occurrence of the character c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char. ​

Synopsis:
#include <string.h>

void *memchr(const void *s, int c, size_t n);
Parameters:

s: Pointer to the memory block to be searched.​

c: Character to search for, passed as an int but internally converted to unsigned char.​

n: Number of bytes to search*/
#include <string.h>
#include <stdio.h>
void *ft_memchr(const void *s, int c, size_t n)
{
   const char *str =  (const char *)s;
    
    int i = 0;
    while (i < n)
    {
        if(*str == (unsigned char)c)
        {
            return (char*)str;
        }
        i++;
        str++;
    }
    /* while (i < n)
    {
        if(str[i] == (unsigned char)c)
        {
            return (void*)str + i;
        }
        i++;
    }*/
    return NULL;
}
int main ()
{
    const void *s = "hello world";
    int c = 'w';
    char *str = ft_memchr(s, c, 7);
    printf("%s\n", str);
}