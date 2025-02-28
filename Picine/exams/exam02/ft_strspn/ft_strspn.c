#include <stdio.h>
int ft_strlen(const char*str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int found (const char*s2, char c)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        if(s2[i]== c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
size_t  ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j = 0;
   
    while(found(accept, s[i]))
    {
        i++;
    }
    
    return i;
} 
int main ()
{
    char str [] = "987654";
    char accept [] = "0123456789";
   size_t len = ft_strspn(str, accept);
   printf("%zu\n", len);
}