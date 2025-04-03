#include <unistd.h>
int check(char *str, char c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int check2(char *str, char str2, int l)
{
    int i = 0;
    while (l > i)
    {
        if (str[i] == str2)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void second(char *str, char *str2)
{
    int i = 0;
    while (str2[i] != '\0')
    {
         if (check(str, str2[i]) && check2(str2, str2[i], i))
        {
            write(1, &str2[i], 1);
        }
        i++;
    }
}
void ft_union(char *str, char *str2)
{
    int i = 0;

    while (str[i] != '\0')
    {
        
        if ( check2(str, str[i], i))
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}
int main(int argc, char **argv)
{
    if(argc == 3)
    {
    ft_union(argv[1], argv[2]);
    //paqefwtdjyino
    second(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}
//the code above is not effecient o(n2), so to make it so we would use more effecient one : 
/*
#include <unistd.h>
#include <stdbool.h>

void ft_union(char *str, char *str2)
{
    bool seen[256] = {false}; // ASCII map to track seen
 characters . The ASCII character set has 256 possible values (0 to 255), covering all possible characters.
    int i = 0;

    while (str[i] != '\0')  // Process first string
    {
        if (!seen[(unsigned char)str[i]])
        {
            seen[(unsigned char)str[i]] = true;
            write(1, &str[i], 1);
        }
        i++;
    }

    i = 0;
    while (str2[i] != '\0') // Process second string
    {
        if (!seen[(unsigned char)str2[i]])
        {
            seen[(unsigned char)str2[i]] = true;
            write(1, &str2[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    else
        write(1, "\n", 1);
    
    return 0;
}
*/