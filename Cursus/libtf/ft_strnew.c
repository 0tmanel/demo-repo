#include <string.h>
char *ft_strnew(size_t size)
{
    char *string = (char*) malloc(size + 1);
    if(!string)
    {
        return NULL;
    }
    ft_memset(string, '\0', size + 1);
    return string;
}
int main ()
{
    printf("%s\n", ft_strnew(10));
}