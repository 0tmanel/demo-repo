#include <unistd.h>/*
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;
    unsigned int j = 0;
    while (i < n )
    {
        dest[j] = src[i];
        i++;
        j++;
       
    }
    dest[j] = '\0';

}
int main ()
{
    unsigned size = 4;
    char src[12] = "hello world!";
    char dest[20];
    ft_strncpy(dest, src, size);
    int j = 0;
    while (dest[j] != '\0')
    {
   write(1, &dest[j], 1); 
    j++;
    }
}*/
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
 char *ft_strncpy(char *dest, char *src, unsigned int n)
 {
   unsigned int i = 0;
   //unsigned int len = n + 1;
  // unsigned int slen  = ft_strlen(src);
   
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while(i < n)
    {
        //After copying characters from src, the second loop (while (i < n)) 
       // ensures that if src is shorter than n, the remaining space in dest 
        //is filled with null characters ('\0').
 //Null Terminator:

//By using the second loop, we guarantee that dest will 
//be properly null-terminated, even if src is shorter than n.
        dest[i] = '\0';
        i++;
    } 
  
    dest[i] = '\0';
    
 /*  Buffer Overflow Risk:

The destination buffer (char dest[5];) in your main() 
function is too small to hold the string you are copying. Specifically,
 you're copying n = 5 characters, but the buffer size is also 5. This means 
 there is no room for the null terminator ('\0'), 
 which is crucial to properly terminate a string in C.
The function will copy 5 characters, but the null terminator 
you add at the end (dest[i] = '\0';) will overflow the buffer since 
it's already full with 5 characters.

Manual Null-Termination:

In standard strncpy, if n is larger than the length of the src string,
 it pads the destination buffer with '\0'. Your code does add a null terminator
  after n characters, but it doesn't handle the case where n is greater 
  than the length of src. If n exceeds the length of src, 
  your function will not pad the destination with null
   characters after copying all characters of src.
    */
    return dest;

 }
int main ()
{
     char src[] = "hello world";
    int n = 5;
    char dest[5];
    char *copied = ft_strncpy(dest, src, n);
   
    
        printf("%s", copied);
       
    //use while only when working with write, 
    //instead just %s and print the whole string 
    printf("\n");
}
/////| KEY POINTS OF STRNCPY|\\\\\*

//Copying with Limit: Copies up to n characters from src to dest.
// This means it doesn't guarantee null termination 
//if the source string is longer than n characters.
//Partial Copy: If src is shorter than n, the remainder
 //of dest is padded with '\0' (null characters). If src is longer than n, 
 //the string is truncated, and no null terminator is added to dest.
//Bounded Copy: Unlike strcpy, it prevents buffer overflow by limiting the 
//number of characters copied to n.