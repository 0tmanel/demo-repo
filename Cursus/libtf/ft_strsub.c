#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char * ft_strsub(char const *s, unsigned int start, size_t len)
{
    if(!s)
    return NULL;
    char * string =  malloc((len + 1) * sizeof(char));
    if(!string)
    {
        return NULL;
    }
    int i = 0;
    while(i < len)
    {
        string[i] = s[start + i];
        i++;
      
    }
    string[i] = '\0';
    return string;
}
int main()
{
    char const *s = "hello world how are you";
    unsigned int start  = 6;
    printf("%s\n", ft_strsub(s, start, 9));
}
