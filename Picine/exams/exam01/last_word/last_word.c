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
 void last_word(char* str)
 {
    int len = ft_strlen(str);
     int i = len - 1;
      while(str[i] == ' ' || str[i] == '\t')
        {
            i--;
        }
        while (str[i] != ' '  && str[i] != '\t' && str[i] != '\0')
        {
            
            i--;
        }
            i++;
         while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
 }

int main (int argc, char **argv)
{

    if(argc == 2)
    {
       last_word(argv[1]);
    }
    else{
        write(1, "\n", 1);
    }
}