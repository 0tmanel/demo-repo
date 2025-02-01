#include <unistd.h>
void rotone(char * str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == 'z' || str[i]== 'Z')
        {
            str[i] -= 25;
        }
        else if((str[i] >= 'a' && str[i] < 'z') || (str[i] >= 'A' && str[i] < 'Z'))
        {
        str[i]++;
        }
        write(1, &str[i], 1);
        i++;
    }
}
int main (int argc, char** argv)
{
    if(argc == 2)
    {
        rotone(argv[1]);
    }
    write(1, "\n", 1);
}