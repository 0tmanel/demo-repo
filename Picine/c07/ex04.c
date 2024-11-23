#include <stdlib.h>
#include <stdio.h>
int checkerror(char *str)
{
   
   if(str[0] == '\0' || str[1] == '\0')
   return 0;
   int i = 0;
   while (str[i] != '\0')
   {
   if(str[i] >= 9 && str[i] <= 13 || str[i]== 32 || str[i] == 43 || str[i] == 45)
   {
      return 0;
   }
      int j = i + 1;
      while(str[j] != '\0') 
      {
         if(str[i]==str[j])
         {
         return 0;
         }
         j++;
      }
      i++;
   }
   return i;
}
int nb_base(char c, char* base)
{
   int i = 0;
   while (base[i] != '\0')
   {
      if(base[i] == c)
      {
         return i;
      }
      i++;
   }
   return -1;
}
int whitspace(char *str, int *ptri)
{
   int i = 0;

   int count = 1;
 
   
   while(str[i] >= 9 && str[i] <= 13 || str[i] ==32)
   {
      i++;
   }
   while  ((str[i] != '\0') && str[i] == '+' || str[i] == '-')
   {
      if(str[i]== '-')
      {
        count *= -1;
      }
      i++;
   }
   *ptri = i;

   return count;   
}
int ft_atoi_base(char* str, char * base)
{
  int nb = 0;
  int i = 0;
  int count;
  int nb2; 
   int base_len = checkerror(base);
   if(base_len >= 2)
   {
      count = whitspace(str, &i);
      nb2 = nb_base(str[i], base);
      while (nb2 != -1)
      {
         nb = (nb * base_len) + nb2;
         i++;
         nb2 = nb_base(str[i], base);
      }
      return nb * count;
   }
   return 0;
}
int len_nb(int nbr, char* base, int len)
{
   int base_length = checkerror(base);
   if(nbr == 0)
   return 1;
   while(nbr != 0)
   {
      nbr /= base_length;
      len++;
   }
   return len;
}
void ft_putnbr_base_v2(int nbr, char* base_to, char* storage)
{
   int index = 0;
   int leng = checkerror(base_to);
   int tem_nb = nbr;
   char buff[33];
   int i;
   if(nbr == 0)
   {
      storage[0] = base_to[0];
      storage[1] = '\0';
      return;
   }
    while (tem_nb != 0)
    {
      buff[index++] = base_to[tem_nb % leng ];
      tem_nb /= leng;
    }
    i = 0;
    while (i < index - 1)
    {
      storage[i] = buff[index -i - 1];
      i++;
    }
    storage[index] = '\0';
}
char *ft_covert_base(char* nbr, char* base_from, char* base_to)
{
   char * result;
   char* finalnb;
   int nb, length;
   if(!checkerror(base_from) || !checkerror(base_to))
   return 0;
   nb = ft_atoi_base(nbr, base_from);
    length = len_nb(nb, base_to, 0);
   result = (finalnb= malloc((length + 1) * sizeof(char)));
   if(result == NULL)
   return 0;
   ft_putnbr_base_v2(nb, base_to, finalnb);
   finalnb[length] = '\0';

   return finalnb;
}
int main ()
{
   char nbr[] = "55";
   char base_from[] = "0123456789";
   char base_to[] = "01";
   char* result = ft_covert_base(nbr, base_from, base_to);
   printf("%s", result);
}