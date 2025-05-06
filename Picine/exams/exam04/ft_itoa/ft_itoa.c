#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int count(int nbr)
{
    int index = 0;
    if(nbr < 0)
    {
        nbr *= -1;
        index++;
    }
    while(nbr != 0)
    {
        nbr /= 10;
        index++;
    }
    return index;
}
char* ft_putnbr(int nbr)
{
    long nb = nbr;
    int len = count(nb);
    char* str = malloc((len + 1) * sizeof(char));
    if(!str)
    {
        return NULL;
    }
    if(nb == 0)
    {
        str[0] = '0';
        return str;
    }
    if(nb < 0)
    {
        str[0] = '-';
        nb *= -1;
    }
    if( nb == 0)
    return str;
    str[len] = '\0';
    int i = len - 1;
    while(nbr != 0)
    {
        str[i--] = nb % 10 + '0';
        nb /= 10;
    }
    return str;
 }
char	*ft_itoa(int nbr)
{
    char * string = ft_putnbr(nbr);
    return string;
}
int main()
{
    char* string = ft_itoa(INT_MIN);
    printf("%s\n", string);
}
// int count(int nbr)
// {
//     int index = 0;
//     if(nbr < 0)
//     {
//         nbr *= -1;
//     }
//     while(nbr != 0)
//     {
//         nbr /= 10;
//         index++;
//     }
//     return index;
// }
// void ft_putnbr(char* str, int nbr, int len)
// {
//     int i = 0;
//     if(nbr < 0)
//     {
//         nbr *= -1;
//         str[i++] = '-';
//     }
//     while(nbr != 0)
//     {
//         str[i++] = nbr % 10 + '0';
//         nbr /= 10;
//     }
//     str[i] = '\0';
//     int first = 0;
//     int last = len - 1;
//     while(first != last)
//     {
//         char temp = str[first];
//         str[first] = str[last];
//         str[last] = temp;
//         first++;
//         last--;
//     }
//  }
//  char	*ft_itoa(int nbr)
// {
//      int len = count(nbr);
//     char* str = malloc((len + 1) * sizeof(char));
//     if(!str)
//     {
//         return NULL;
//     }
//     ft_putnbr(str, nbr, len);
//     return str;
// }
// int main()
// {
//     char* string = ft_itoa(39405);
//     printf("%s\n", string);
// }