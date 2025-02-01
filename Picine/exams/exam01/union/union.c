#include <unistd.h>
int pos(char* str, char c, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if( str[i] == c)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int pos2(char *str, char c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i]== c)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void ft_union(char*str, char*str2)
{
     
    int i = 0;
    
    while (str[i] != '\0')
    {
       //First Loop (Processing str):Correctly writes all unique characters of str by checking if the character has appeared before the current index
            if (pos(str, str[i], i) == 1)
            {
                write(1, &str[i], 1);
                
            }
        i++;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
       //Second Loop (Processing str1): Uses check_doubles2 to ensure the character is not in str. Uses check_doubles1 to ensure the character is unique in str1 up to the current index.
            if (pos2(str, str2[j]) == 1)
            {
                if(pos(str2, str2[j], j) == 1)
                {
                write(1, &str2[j], 1);
                  
                }
            }
            
        j++;
    }
    write(1, "\n", 1);
}
int main (int argc, char **argv)
{
    if(argc == 1)
    {
        write(1, "\n", 1);
    }
   ft_union(argv[1], argv[2]);

}