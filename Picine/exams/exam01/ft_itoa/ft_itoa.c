#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int count(int nbr)
{
    int index = 0;
    if(nbr < 0)
    {
        index ++;
        nbr *= -1;
    }
    
     while(nbr > 0)
    {
        nbr /= 10;
        index ++;
    }
   
    return index;
}
char *ft_putnbr(int number, char* string , int* lenght,  int i)
{
    long nbr = number;
   int len = *lenght;
    string[len]= '\0';
    if(nbr < 0)
    {
        string[0] = '-';
        nbr *= -1;
        i = 1; 
    }
    len--;
    while(nbr > 0)
    {
        string[len] = nbr % 10 + '0';
       nbr /= 10;
       len--;   
    }

    return string;
}
char *ft_itoa(int nbr)
{
    int index  = 0;
    int len = count(nbr);
    
    char *string = malloc((len + 1) * sizeof(char));
    if(!string)
    {
        return NULL;
    }
    int i = 0;
    return ft_putnbr(nbr, string, &len,  i);
}
int main ()
{
    char *string = ft_itoa(-7483647);

        printf("%s\n", string);
    
}