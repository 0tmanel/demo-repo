#include <stdio.h>
#include <stdlib.h>
int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 int calcu_nbr(int nb, char *base_to)
 {
    int len = ft_strlen(base_to);
   int index = 0;
   if(nb < 0)
   {
    nb *= -1;
    index++;
   }
   while(nb != 0)
   {
      nb = nb / len;
      index++;
   }
   return index;
 }
 char *ft_putnbr_base(int nbr, int length, char* base_to)
 {
     //long long nbr = nb;
    int len = ft_strlen(base_to);
    int is_negative = 0;
    if(nbr < 0)
    {
        is_negative = 1;
        nbr *= -1;
    }
   char* array = malloc((length + 1) * sizeof(char));
        while(nbr != 0){
        array[length--] = base_to[nbr % len];
        nbr /= len;
     }
     if(is_negative)
     {
        array[length] = '-';
     }
     return array;
 }