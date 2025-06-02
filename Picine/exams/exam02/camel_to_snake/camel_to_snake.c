#include <stdio.h>
#include <unistd.h>
int is_upper(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}
void camel_case(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(is_upper(str[i]))
        {
            write(1, "_", 1);
            str[i] += 32;
        }
        write(1, &str[i], 1);
        i++;
    }
}
int main (int argc, char**av)
{
    if(argc == 2)
    {
    camel_case(av[1]);
    }
    write(1, "\n", 1);
}