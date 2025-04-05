//What strrchr Should Do
//Return a pointer to the last occurrence of character c in string s.
//If c == '\0', return a pointer to the null terminator at the end of the string.
//If c is not found, return NULL
#include <stdio.h>
#include <string.h>
/*char *ft_strrchr(const char *s, int c)
{
    int temp = -1;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
        {
            temp = i;
        }
        i++;
    }
    if(c == '\0')
    return (char*)(s + i);
    if(temp >= 0)
    return (char*)s + temp;
    return NULL;
}*/
/*
int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
char *ft_strrchr(const char *s, int c)
{
    int len = ft_strlen(s);
    if(c == '\0')
    return (char*) s + len;
    while(0 <= len)
    {
        if(s[len] == (char)c)
        {
             return (char*)s + len;
        }
        len--;
    }
    return NULL;
}*/
char *ft_strrchr(const char *s, int c)
{
    const char *last = NULL;

    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }

    if (c == '\0')
        return (char *)s;

    return (char *)last;
}

int main ()
{
    const char *s = "hello world";
    int c = 'o';
    printf("%s\n", ft_strrchr(s, c));
}