#include <unistd.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 void first_word(char* str)
 {
     int i = 0;
        while(str[i] == ' ' || str[i] <= '\t')
        {
            i++;
        }
        while (str[i] != ' ' && str[i] != '\0' && str[i] == '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
 }
int main (int argc, char **argv)
{
    char* str = argv[1];

    if (argc == 2){
       first_word(argv[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}