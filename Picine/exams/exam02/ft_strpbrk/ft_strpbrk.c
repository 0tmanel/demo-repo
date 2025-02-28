#include <stdio.h>
int found(const char* s2, char c)
{
    
    int i = 0;
    while (s2[i] != '\0')
    {
        if(s2[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
char	*ft_strpbrk(const char *s1,  const char *s2)
{
    int i= 0;
    while (*s1)
    {
        if(found(s2, *s1))
        {
          return  (char*)s1;;
        }
        s1++;
    }
    return  NULL;
}
int main ()
{
     const char *s1 = "caus i love you";
    const char *s2 = "hello";

    char *str = ft_strpbrk(s1, s2);
    printf("%s\n", str);
}