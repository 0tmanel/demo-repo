//strmapi is like saying:

//"Change each character based on what it is and where it is in the string."
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
char to_upper(unsigned int i, char str)
{
     if (i % 2 == 0 && str >= 'a' && str <= 'z') 
     {
      return str - 32;
     }
     return str;
   
}
char * ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if(!s)//IF someone called ft_strmapi(NULL, f), it will crash
    return NULL;
    char* string = malloc((ft_strlen(s) + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0;
    while(s[i] != '\0')
    {
        string[i] = f(i , s[i]);
        i++;
    }
    string[i] = '\0';
    return string;
}
int main ()
{
    char const *s = "hello";
    printf("%s\n", ft_strmapi(s, &to_upper));
}