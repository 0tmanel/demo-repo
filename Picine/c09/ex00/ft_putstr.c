#include <unistd.h>
char* ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    str[i] = '\0';
    return str;
}