//How is it different from memcpy()? 

//memcpy() simply copies data one by one from one location to another. On the other hand memmove() copies the data first to an intermediate buffer, then from the buffer to destination.
//memcpy() leads to problems when strings overlap. 
#include <stdio.h>
#include <string.h>

 void *ft_memmove(void *dst, const void *src, size_t len)
 {
     unsigned char* ptr = ( unsigned char*)dst;
    const unsigned char* ptr2 = (const unsigned char*)src;
    char *buffer = (char*) malloc(len * sizeof(char));
    int i = 0;
    while (i < len)
    {
        buffer[i] = ptr2[i];
        i++;
    }
    i = 0;
    while(i < len)
    {
        ptr[i] = buffer[i];
        i++;
    }
    free(buffer);
    return dst;
 }
 
int main() 
{ 
    char str[100] = "Geeksfor"; 
   
    memcpy(str + 5, str, strlen(str) + 1); 
    printf("memcpy :%s\n ", str); 
      
    // when overlap happens then it just ignore it 
    //memmove(str + 2, str, strlen(str) + 1); 
   // printf("memcpy overlap : %s\n ", str); 
   // printf("memmove overlap : %s\n ", str);
  
    // when overlap it start from first position 
    //char* string = ft_memmove(second + 2, first, 5); 
   // printf("ft_memmove overlap : %s\n ", str); 

  
    return 0; 
}