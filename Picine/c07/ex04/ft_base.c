 #include <stdio.h>
 #include <stdlib.h>
 int ft_nbr_lenght(int nbr_d, char* base_to, int lenght);
 void ft_putnbr_base(int nbr, char *finalNumber, char *base_to);
 int checkerror(char *base)
 {
    int i;
    int j;
    i = 0;
    if(base[0] == '\0' || base[1] == '\0')
    return 0;
    while (base[i] != '\0')
    {
        j = i + 1;
        while (base[j] != '\0')
        {
            if(base[j] == base[i])
            return 0;
            j++;
        }
        i++;
    }
    return (i);
 }
 int whitespace(char *nbr, int *ptr_i)
 {
    int i = 0;
    int sign = 1;
    while (nbr[i] != '\0')
    {
        if(nbr[i] >= 9 && nbr[i] <= 13 || nbr[i] == 32)
        {
            i++;
        }
        if(nbr[i] == '-' || nbr[i] == '+')
        {
            if(nbr[i] == '-')
            {
                sign *= -1;
            }
            i++;
        }
        i++;
    }
    *ptr_i = i;
    return sign;
 }
 int char_to_value(char c, char *base_to)
 {
    int i = 0;
    while (base_to[i] != '\0')
    {
        if(base_to[i] == c)
        {
        return i;
        }
        i++;
    }
    return -1;

 }
 int ft_atoi_base(char *nbr, char*base_to)
 {
    int sign;
    int  i = 0;
    int value;
    int result = 0;
    int base_to_length = checkerror(base_to);
    //i am not sure if this base_to or base from
    if(base_to_length >= 2)
    {
    sign = whitespace(nbr, &i);
    value = char_to_value(nbr[i], base_to);
    while (value != -1)
    {
        value = char_to_value(nbr[i], base_to);
        if(value == -1)
        break;

        result = result * base_to_length + value;
        i++;
    }
    return result * sign ;
    }
    return 0;
 }
 char *ft_convert_base(char *nbr, char *base_from, char *base_to)
 {
    char *finalNumber;
    int nbr_d;
    int nbr_lenght;
    if(!checkerror(base_from)|| !checkerror(base_to))
    return 0;

    nbr_d = ft_atoi_base(nbr, base_to);
    nbr_lenght = ft_nbr_lenght(nbr_d, base_to, 0);

    finalNumber = malloc((nbr_lenght + 1) * sizeof(char));

    ft_putnbr_base(nbr_d, finalNumber, base_to);
    finalNumber[nbr_lenght] = '\0';
    return finalNumber;

 }
 int main ()
 {
    char nbr[] = "349";
    char base_from[] = "0123456789";
    char base_to[] = "0123456789ABCDEF";

   char* nbr_baseTo = ft_convert_base(nbr, base_from, base_to);
   printf("%s\n", nbr_baseTo);
 }