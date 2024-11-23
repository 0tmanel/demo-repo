#include <unistd.h>
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;
    unsigned int j = 0;
    while (i < n )
    {
        dest[j] = src[i];
        i++;
        j++;
       
    }
    dest[j] = '\0';

}
int main ()
{
    unsigned size = 4;
    char src[12] = "hello world!";
    char dest[20];
    ft_strncpy(dest, src, size);
    int j = 0;
    while (dest[j] != '\0')
    {
   write(1, &dest[j], 1); 
    j++;
    }
}
