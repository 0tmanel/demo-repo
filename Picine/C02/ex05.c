#include <unistd.h>
#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
  
   while (src[i] != '\0' && size - 1 > i)
   {
    dest[i] = src[i];
    i++;
   }
   if (size > 0)
   dest[i] = '\0';

}
int main () 
{
    char src[] = "hello otman";
    char dest[7];
    unsigned int dsize = 7;
    int length  = ft_strlcpy(dest,src, dsize);
    printf("%d", length);
}