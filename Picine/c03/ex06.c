#include <stdio.h>
int ft_strlen2(char* src)
{
    int i = 0;
    while (src[i] != 0)
    {
        i++;
    }
    return i;
}
int ft_strlen(char *dest)
{
  
    int  j = 0;
    while (dest[j] != 0)
    {
        j++;
    }
    return j;
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int destl  = ft_strlen(dest);
    unsigned int srcl = ft_strlen2(src);
    int i = 0;
    
    
   if (size < destl)
   return size + srcl;
   while (dest[i] != '\0' && i < size)
   {
    i++;
   }
   unsigned int j = 0;
 while ( src[j] != 0 && i < size - 1)
    {
        dest[i] = src[j];
        i++;
        j++;

    }
    if(i < size)
    {
        dest[i + j] = '\0';
    }
    return srcl + destl;

}
int main ()
{
    char dest [12] = "hello ";
    char src []= "world";
    unsigned int size = 12;
   int result = ft_strlcat(dest, src, size);
   printf("%d", result);
}
