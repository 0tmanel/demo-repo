 #include <unistd.h>
int main (int argc, char*argv[])
{
    int i  = 0;
    //this condition checks if there is only one argument passed to the program (which is the program name itself).
    //argc == 1 means no additional arguments were given, so only the program name (stored in argv[0]) is present.
    if(argc == 1)
    {
    while (argv[0] [i] != '\0')
    {
        write(1, &argv[0][i], 1);
        i++;
    }
    }
    write(1, "\n", 1);
}