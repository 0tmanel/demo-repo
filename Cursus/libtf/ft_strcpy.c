#include <stdio.h>
 char * ft_strcpy(char * dst, const char * src)
 {
    int i = 0;
    while(src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
 }
 int main ()
 {
    char dest[23] = "hello world hwo are you";
    const char src[] = "hello my name is Osman";
    char* string = ft_strcpy(dest, src);
    printf("%s\n", string);
 }