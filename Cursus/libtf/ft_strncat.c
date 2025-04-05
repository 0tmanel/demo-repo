#include <stdio.h>
char *ft_strncat(char *dest, const char *src, size_t n)
{
    int i = 0;
    while (dest[i] != '\0')
    i++;
    int j = 0;
    while (src[j] != '\0' && j < n)
        dest[i++] = src[j++];
    dest[i] = '\0';
    return dest;
}
int main ()
{
    char dest[20] = "hello, ";
    char src[] = "my name is otman";
   printf("%s\n", ft_strncat(dest, src, 5));
}