#include <stdio.h>
/*int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }*/
 char *ft_strcat(char *dest, char *src)
 {
    int j = 0;
   // int len = ft_strlen(dest);
   int i = 0;
   while (dest[i] != '\0')
   {
    i++;
   }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
return dest;

 }
int main ()
{
    char src[] = " world";
    char dest[] = "hello";
   char *destsrc =  ft_strcat(dest, src);
   printf("%s\n", destsrc);
}