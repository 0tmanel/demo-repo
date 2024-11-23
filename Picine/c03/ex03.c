#include <unistd.h>
 char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i = 0;
    int j;
    while (dest[i] != 0)
    {
        i++;
    }
    j = 0;
    while (j < nb)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';

}
int main ()
{
    char dest [15] = "hello, ";
    char src [] = "world";
    unsigned int nb = 3;
    ft_strncat(dest, src, nb);
    int i = 0;
    while (dest[i] != 0)
    {
        write(1, &dest[i], 1);
        i++;
    }
}