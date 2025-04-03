#include <unistd.h>
#include <limits.h>
  void ft_putchar(char c)
  {
    write(1, &c, 1);
  }
void	ft_putposnbr(int n)
{
    if (n > 9)
        ft_putposnbr(n / 10);
    ft_putchar(n % 10 + '0');
}
int main (int argc,  char** av)
{

    if(argc > 1)
    {
        ft_putposnbr(argc - 1);
    }
    else if(argc == 1)
    {
         write(1, "0", 1);
    }
    write(1, "\n", 1);
}
/*#include <unistd.h>

void	print_nbr(int n)
{
	if (n >= 10)
		print_nbr(n /10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int main (int argc, char **argv)
{
	int index = 1;
	if (argc == 1)
		write(1, "0", 1);
	else 
	{
		while (argv[index])
			index++;
		print_nbr(index - 1);
	}
	write(1, "\n", 1);	
	return (0);
}*/