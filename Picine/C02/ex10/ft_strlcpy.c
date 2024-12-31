//strlcpy is a function that provides a safer and more predictable
// way to copy strings in C. It's designed to avoid the common 
//pitfalls of traditional string copying functions like strcpy, which can
// lead to buffer overflows if the destination buffer is not large enough.
//strlcpy returns the total length of the string it tried to create, 
//which is the length of src. If this length is greater than
 //or equal to size, it means the string was truncated.
//This return value can be useful to check if truncation occurred, 
//i.e., if the source string was too long to fit in the destination buffer.

////| RISKS OF STRNCPY|\\\\*
//No Null-Termination: If src is longer than n, strncpy does not null-terminate
// dest, which can lead to issues if you later try to treat dest as a string.
//Padding with Null Characters: If the source string is shorter than n, 
//it pads the remaining space in dest with '\0', which could introduce 
//unnecessary null characters if you're not careful.
#include <stdio.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
 {
    unsigned int srclen = ft_strlen(src);
    if(srclen + 1 < size)// if the passed size was bigger than length of src
                        //we copy up to src length + 1
    {
    unsigned int i = 0;
     while (i < srclen + 1)
    {//When the loop reaches i == srclen, it copies the null
    // terminator ('\0') from src to dest.
        dest[i] = src[i];
        i++;
    }
   
    }
    else{
        unsigned int i = 0;
    while (i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }//The string src is too large to fit into dest, so you can't
     //copy the entire string.You can copy up to size - 1 characters,
     // but you manually add a null terminator ('\0') at the last position 
      //of dest to ensure it remains a valid C string.
        dest[size-1] = '\0';
    }
    
    
    return srclen;
  
 }
int main()
{
    char src[] = "hello world";
    unsigned int size = 20;
    char dest[size];
    unsigned int len = ft_strlcpy(dest, src, size);
    printf("%d\n", len);

}