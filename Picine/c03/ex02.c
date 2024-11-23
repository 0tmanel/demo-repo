#include <unistd.h>
char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    while (dest[i] != 0)
    {
        i++;
    }
    while (src[j] != 0)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[j] = '\0';

}
int main ()
{
    char dest [15] = "hello, ";
    char src [] = "world";
    ft_strcat(dest, src);
    int i = 0;
    while (dest[i] != 0)
    {
        write(1, &dest[i], 1);
        i++;
    }
}