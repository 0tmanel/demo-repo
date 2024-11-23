#include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i = 0;
    while (s1[i] == s2[i] && i < n)
    {
       
            i++;
    }
        return s1[i] - s2[i];
}
int main ()
{
    char s1[] = "helkdhfjf";
    char s2[] = "hellpouyhd";
    unsigned int n = 3;
    int result = ft_strncmp(s1, s2, n);
    printf("%d", result);
}