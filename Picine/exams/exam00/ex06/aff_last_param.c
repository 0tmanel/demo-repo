#include <unistd.h>
int main (int argc, char* argv[])
{
    if(argc > 1)
    {
        int i = 0;
        
        while (argv[argc - 1][i] != '\0')
        {
            write(1, &argv[argc - 1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
} // or this 
/* 
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*argv[argc - 1])
			write(1, argv[argc - 1]++, 1);
	write(1, "\n", 1);
	return (0);
}
*/