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
