
//No bounds checking: strcpy does not check if the destination buffer 
//is large enough to hold the copied string.
 //If the destination buffer is smaller than the source string,
  //this can lead to a buffer overflow, which is a common source
  // of security vulnerabilities.
//Returns: It returns a pointer to the destination (dest).
#include <stdio.h>
 char *ft_strcpy(char *dest, char *src)
 {
    /////ARRAY NOTATION\\\\\\\*
    /*int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    src[i] = '\0'*/;

    ////POINTER NOTATION\\\\\*
    char *temp = dest;
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return temp;
 }
 int main()
 {
    char src[] = "hello world";
    char dest[12];
    char *copied = ft_strcpy(dest, src);
   
    
        printf("%s", copied);
       
    //use while only when working with write, 
    //instead just %s and print the whole string 
    printf("\n");
 }
 //A buffer overflow occurs when data is written beyond the boundaries 
 //of a buffer (a fixed-size memory area). This can lead to several problems,
  //including corruption of data, unexpected behavior, and even security vulnerabilities.

//In C and other low-level languages, buffers are often used to store data
 //such as strings or arrays. If the data written to the buffer exceeds its 
 //allocated size, it can overwrite adjacent memory, causing unpredictable
 // behavior and potentially harmful consequences.