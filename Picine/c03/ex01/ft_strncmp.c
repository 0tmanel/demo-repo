#include <stdio.h>
#include <string.h>

 int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i = 0;
    while (i < n && s1[i] == s2[i])
    {  
        i++;
    }
    return s1[i] - s2[i];
}
int main ()
{
    char s1[] = "abc";
    char s2[] = "abcd";
    unsigned int n = 4;

   int res =  ft_strncmp(s1, s2, n);
 //int res =  strncmp(s1, s2, n);
   printf("%d\n", res);
}
