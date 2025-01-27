#include <unistd.h>
// you can do this to practice while

int main()
{
    char i = '9';
    while (i >= '0')
    {
        write(1, &i, 1);
        i--;
    }
    write(1, "\n", 1);
}
/*
or you can do the lazy way
int main()
{

    write(1, "9876543210\n", 11);
    
}*/