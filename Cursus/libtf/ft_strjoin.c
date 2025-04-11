 #include <stdlib.h>
#include <stdio.h>
 int ft_strlen(char const *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
char * ft_strjoin(char const *s1, char const *s2)
{
    int len = ft_strlen(s1) + ft_strlen(s2);
    char* string = malloc((len + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0; 
    //here we used just the indices , we could use the pointers and keep one index i
    while(s1[i] != '\0')
    {
        string[i] = s1[i];
        i++;
    }
    int j = 0;
    while(s2[j] != '\0')
    {
        string[i + j] = s2[j];
        j++;
    }
    string[i + j] = '\0';
    return string;
}
int main ()
{
    char const* s1 = "hello ";
    char const *s2  = "world";
    printf("%s\n", ft_strjoin(s1, s2));
}