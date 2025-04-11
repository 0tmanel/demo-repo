#include <string.h>
#include <stdio.h>
int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    int i = 0;
    while(i < n && s1[i] == s2[i])
    {
        i++;
    }
    //If we compared exactly n characters and they match, return 1
    // If the loop ends and both strings are equal at position i, return 1
     if(n == i || s1[i] == s2[i])
       return 1;
    return 0;
}
int main()
{
    char const* s1 = "abc";
    char const *s2 = "abcxyz";
    printf("%d\n",ft_strnequ(s1, s2, 5));

}