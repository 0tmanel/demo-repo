#include <unistd.h>
int main ()
{
    //you can do this lazy way
    char str[] = "Hello World!";
    int i = 0;
    while (str[i] != '\0')
    {
    write(1, &str[i], 1);
    i++;
    } 
    write(1, "\n", 1);
    // or this lazy way
    /*
    write(1, "Hello World!", 12);
    write(1, "\n", 1);
    */
}