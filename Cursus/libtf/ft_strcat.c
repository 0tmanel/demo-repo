//The strcat function appends the src string to the end of the dest string. The terminating null byte (\0) of dest is overwritten by the first character of src, and a new null byte is added at the end of the concatenated string.'
#include <stdio.h>
char *ft_strcat(char *dest, const char *src)
{
    int i = 0;
    while (dest[i] != '\0')
    i++;
    int j = 0;
    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return dest;
}
int main ()
{
    char dest[20] = "hello, ";
    char src[] = "my name is otman";
   printf("%s\n", ft_strcat(dest, src));
}