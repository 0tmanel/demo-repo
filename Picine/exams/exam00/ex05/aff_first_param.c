#include <unistd.h>
int main (int argc, char *argv[])
{
    //you can do this 
    if(argc < 1)
    {
        write(1, "\n", 1);
    }
    else{
        int i = 0;
        while (argv[1] [i] != '\0')
        {
            write(1, &argv[1] [i], 1);
            i++;
        }
        write(1, "\n",1);
    }
   // or this
   /*
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*argv[1])
			write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
*/
}