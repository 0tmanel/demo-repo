#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
void help(char *str)
{

    int first = 0;
    while(str[first] == 32 || str[first] == 't')
    {
        first++;
    }
    int last = ft_strlen(str) - 1;
    while((str[last] == 32 || str[last] == 't'))
    {
        last--;
    }
    while (first <= last)
    {

        if (str[first] == 32 || str[first] == '\t')
        {
            while (str[first] == 32 || str[first] == '\t')
            {
                first++;
            }
            write(1, " ", 1);
        }
        write(1, &str[first], 1);
        first++;
    }
}
int main(int argc, char **argv)
{
    if(argc == 2)
    {
    help(argv[1]);
    }
    write(1, "\n", 1);
}
/*
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i = 0;
	int		space = -1;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (space == 1)
					write(1, " ", 1);
				space = 0;
				write(1, &av[1][i], 1);
			}
			else if (space == 0)
				space = 1;
			i++;
		}
	}
	write(1, "\n", 1);
}*/