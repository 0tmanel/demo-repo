#include <unistd.h>

void ft_putnbr_base(int nbr, char *base)
{
    int len;
    int mod;
    int i = 0;

    while (base[i] != 0)
    {
    i++;
    }
    if(nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    if (i == 8)
    {
        if (nbr != 0)
        {
            ft_putnbr_base(nbr / 8, base);
            mod = nbr % 8 + '0';
            write(1, &mod, 1);
        }
    }
    if (i == 2)
    {

        if (nbr != 0)
            ft_putnbr_base(nbr / 2, base);
        mod = nbr % 2 + '0';
        write(1, &mod, 1);
    }
    if (i == 16)
    {
        int j = 0;
     
            if (nbr != 0)
            {
                ft_putnbr_base(nbr / 16, base);
                mod = nbr % 16;
                while (base[j] != 0)
                {
                    if(j == mod)
                    {
                    write(1, &base[j], 1);
                    }
                    j++;
                }
                
            }
                
        
    }
}
int main()
{
    int nbr = 86 ;
    char base[] = "01";
    ft_putnbr_base(nbr, base);
}