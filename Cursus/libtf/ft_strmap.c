#include <stdlib.h>
 #include <stdio.h>
 //strmap is like saying:
//"Change each character using the same rule, no matter where it is."
 int ft_strlen(char const *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
char to_upper(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c;
}
char * ft_strmap(char const *s, char (*f)(char))
{
    if(!s)//IF someone called ft_strmap(NULL, f), it will crash
    return NULL;
    char* string = malloc((ft_strlen(s) + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0;
    while(s[i] != '\0')
    {
        string[i] = f(s[i]);
        i++;
    }
    string[i] = '\0';
    return string;
}
int main ()
{
    char const *s = "hello";
    printf("%s\n", ft_strmap(s, &to_upper));
}