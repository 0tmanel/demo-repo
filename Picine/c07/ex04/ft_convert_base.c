 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 char* ft_putnbr_base(int result, char*finalNumber, char *base_to);
 int ft_nbr_len(int number, char *base_to_len, int lenght);
 int checkerror(char *str)
{
    int i;
    int j;
    
    i = 0;
    if (str[0] == '\0' || str[1] == '\0')
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
            return (0);
        j = i + 1;
        while (str[j] != '\0')
        {
            if (str[i] == str[j])
                return (0);
            j++;
        }
        i++;
    }
    return (i);
} 
int whitespase (char *str, int* ptr_i)
{
    int sign = 1;
    int i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            {
                i++;
            }
            while (str[i] == '-' || str[i] == '+')
            {
                if (str[i] == '-')
                {
                    sign *= -1;
                }
                i++;
            }
            *ptr_i = i;
            return sign;
}
int char_to_value(char c, char *base)
{
    int i = 0;
    while (base[i] != '\0')
    {
        if(c == base[i])
        return i;
        i++;
    }
    return -1;
}
int ft_atoi_base(char *nbr, char *base)
{
    int i = 0;
    int sign ;
    int result = 0;
    int value;

   
         int base_len = checkerror(base);
         if(base_len >= 2)
         {

                sign = whitespase(nbr, &i);
               value = char_to_value(nbr[i], base);
            while (value != -1)
            {
               result = (result * base_len) + value;
                i++;
                value = char_to_value(nbr[i], base);
            }
            return (result * sign);

         }
         return 0;
}
 char* ft_convert_base(char *nbr, char *base_from, char *base_to)
 {
    int number_len;
    int number;
   char *finalNumber;
   char *d;
    if(! checkerror(base_from) || !checkerror(base_to))
    {
        return 0;
    }
    number = ft_atoi_base(nbr, base_from);
    number_len = ft_nbr_len(number, base_to, 0);
    d = (finalNumber = (char *)malloc ((number_len + 1) * sizeof(char)));
    if(!d)
    {
        return 0;
    }
    ft_putnbr_base(number, finalNumber, base_to);
    finalNumber[number_len] = '\0';
             return finalNumber;
 }
 int main ()
 {
    char nbr[]= "-2147483648";
    char base_from[] = "0123456789";
    char base_to[] = "0123456789ABCDEF";
    char * array = ft_convert_base(nbr, base_from, base_to);
    printf("%s\n", array);
  // printf("\n");
 }