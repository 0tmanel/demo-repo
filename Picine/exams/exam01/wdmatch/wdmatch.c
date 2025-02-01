#include <unistd.h>
int checkDouble(char* str, char*str2)
{
    int i= 0;
    int j =0;
    while (str[i] != '\0')
    {
        while (str2[j] != '\0')
        {
            if(str[i] == str2[j])
            {
                break;
            }
            j++;
        }
             if(str[i] != str2[j])
            {
                return 0;
            }
        i++;
    }
    return 1;
}
void ft_putstr(char *str)
  {
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
  }
void wdmatch(char*str, char *str2)
{
    int j = 0;
    int i = 0;
    if( checkDouble(str, str2))
    {
        ft_putstr(str);
    }
}
int main (int argc, char **argv)
{
    if(argc == 3)
    {
        wdmatch(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}
/*
int		main(int ac, char **av)
{
	int i;
	int j;
	int wdlen;

	i = 0;
	j = 0;
	wdlen = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			while (av[2][j] != '\0')
			{
				if (av[1][i] == av[2][j])
				{
					wdlen++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (wdlen == ft_strlen(av[1]))
			ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
*/