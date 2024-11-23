#include <stdio.h>
#include <unistd.h>
char ft_strcpy(char *src, char *dest)
{
    int i = 0;
    int j = 0;
    while (src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}
int main ()
{
    char src[12] = "hello world!";
    char dest[20];
    ft_strcpy(src, dest);
    int i = 0;
    while (dest[i] != 0)
    {
   write(1, &dest[i], 1); 
    i++;
    }
}