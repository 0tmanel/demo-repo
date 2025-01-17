int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
int ft_nbr_lenght(int nbr_d, char* base_to, int lenght)
{
    long nb;
    int base_lenght = ft_strlen(base_to);
    if (nbr_d < 0)
    {
        nb = (unsigned int) (-nbr_d);
        lenght++;
    }
    else
        nb  = (unsigned) nbr_d;
    while (nb >= base_lenght)
    {
        nb /= base_lenght;
        lenght++;
    }
    lenght++;
    return lenght;
}
void ft_putnbr_base(int nbr, char *finalNumber, char *base_to)
{
    int base_lenght = ft_strlen(base_to);
    int lenOf_final_number = ft_nbr_lenght(nbr, base_to, 0);

    int i = 0;
    if(nbr < 0)
    {
        finalNumber[0] = '-';
        nbr *= -1;
        i = 1;

    }
    lenOf_final_number--;
    if(nbr < base_lenght)
    {
        finalNumber[i] = base_to[nbr];
    }
    while(nbr >= base_lenght)
    {
        finalNumber[lenOf_final_number] = base_to[nbr % base_lenght];
        nbr /= base_lenght;
        lenOf_final_number--;
    }
}