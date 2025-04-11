#include <stdio.h>
#include <stdlib.h>
void *ft_memalloc(size_t size)
{
    void *array =(int*) malloc(size);
    //void * means: “this is a pointer to something, but I don’t know what yet.”
    if(!array)
    {
        return NULL;
    }
    //ft_bzero(array, size);
    int i = 0;
    //you can't index a void *, so we cast to unsigned char, it is a byte-sized integer type that can hold values from 0 to 255. It can represent characters (like ASCII) or just raw numbers — it’s the most flexible type for low-level, byte-by-byte work.
    unsigned char * ptr = (unsigned char*)array;
    while(i < size)
    {
      ptr[i] = 0;
        i++;
    }
    return array;
}
int main ()
{
    ft_memalloc(7);
}