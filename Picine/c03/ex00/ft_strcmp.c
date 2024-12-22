#include <stdio.h>
#include <string.h>
 int ft_strcmp(char *s1, char *s2)
 {
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return *s1 - *s2;
/*
This condition ensures that as long as both strings have 
characters that are equal, the loop continues.
It also ensures that if str1 reaches the null terminator ('\0'), 
the loop will stop because *str1 will be 0, which causes the condition 
to fail (even if str2 hasn't reached the null terminator yet).

    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' )
    {
        i++;
    }
    return s1[i] - s2[i];

*/
 }
int main ()
{
    char s1[] = "hello";
    char s2[] = "hello";
   int res =  ft_strcmp(s1, s2);
  // int res =  strcmp(s1, s2);
   printf("%d\n", res);
}