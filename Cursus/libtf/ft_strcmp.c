//Compares the two strings s1 and s2, character by character.
//Comparison is lexicographical (based on ASCII values).
//Stops at the first differing character or when a \0 is encountered.

//🔁 Return value:
//0 if the strings are equal.
//A negative value if s1 < s2.
//A positive value if s1 > s2.
#include <string.h>
#include <stdio.h>
int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    return s1[i] - s2[i];
}
int main()
{
    const char* s1 = "hello";
     const char* s2 = "hello";
     printf("%d\n", ft_strcmp(s1, s2));
}