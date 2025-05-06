#include <stdio.h>
//1 : used in OS
//Both memset and bzero are used to initialize memory blocks when creating buffers, memory pools, or allocating space for data structures. For example, OS kernel code might use these functions to clear memory when allocating space for new processes or threads.
//2: Sensitive Data Erasure:
//One of the most important use cases for memset and bzero is securely clearing sensitive data, such as passwords, cryptographic keys, or other private information, before it is discarded or overwritten. The goal is to prevent any sensitive data from being left behind in memory after it is no longer needed.
void* ft_memset(void* str, int to_chang, size_t how)
{
    unsigned char* ptr =  (unsigned char*)str;
    size_t i = 0;
    while(i < how)
    {
        ptr[i] = (unsigned char)to_chang;
        i++;
    }
    return ptr;
}
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("Before memset(): %s\n", str);

   
   void* string = ft_memset(str + 13, '.', 8*sizeof(char));

    printf("After memset():  %s\n", str);
    return 0;
}
/*Among the collection of memory-manipulating functions, the most common is easily memset():
    #include <string.h>
void * memset (void *s, int c, size_t n);
A call to memset() sets the n bytes starting at s to the byte c and returns s. A frequent
use is zeroing a block of memory:
    // zero out [s,s+256) 
    memset (s, '\0', 256);
bzero() is an older, deprecated interface introduced by BSD for performing the same task. New code should use memset(), but Linux provides bzero() for backward com‐ patibility and portability with other systems:
    #include <strings.h>
void bzero (void *s, size_t n);
The following invocation is identical to the preceding memset() example:
    bzero (s, 256);
Note that bzero() (along with the other b interfaces) requires the header <strings.h> and not <string.h>.
##ALERT
Do Not Use memset() if You Can Use calloc()!
Avoid allocating memory with malloc() only to immediately zero the provided memory with memset(). While the result may be the same, foregoing the two functions for a single calloc(), which returns zeroed memory, is superior. Not only will you make one less function call, but calloc() may be able to obtain already zeroed memory from the kernel. In that case, you avoid manually setting each byte to 0, improving performance.*/