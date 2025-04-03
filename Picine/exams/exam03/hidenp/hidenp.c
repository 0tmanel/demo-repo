#include <stdio.h>
#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
void hidenp(char *str, char *str2)
{
    int index = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        while (str2[j] != '\0')
        {
            if (str[i] == str2[j])
            {
                j++;
                index++;
                break;
            }
            j++;
        }
        i++;
    }
    if (ft_strlen(str) == index)
    {
        write(1, "1", 1);
    }
    else
    {
        write(1, "0", 1);
    }
}
/*
while (str2[i] != '\0')
{
    if (str[j] == str2[i])
    {
        str[j]++;
    }
    i++;
}
if (str[j] == '\0')
    write(1, "1", 1);
else
{
    write(1, "0", 1)
}
*/
int main(int argc, char **av)
{
    if (argc == 3)
    {
        hidenp(av[1], av[2]);
    }
    write(1, "\n", 1);
}