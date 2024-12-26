#include <stdio.h>
 char *ft_strncat(char *dest, char *src, unsigned int nb)
 {
   unsigned int i = 0;
   unsigned int j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (j < nb && src[j] != '\0')
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
    char src[7] = " world";
    char dest[20] = "hello";
    unsigned int nb = 3;
   char *destsrc =  ft_strncat(dest, src, nb);
   printf("%s\n", destsrc);
}