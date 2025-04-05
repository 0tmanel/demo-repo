#include <string.h>
#include <stdio.h>
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    if(n = 0)
    return 0;
    int i = 0;
    while(s1[i] == s2[i] && i < n)
    {
        if(s1[i] == '\0')
        {
        break;
        //thsi condition is not strinctly necessary. it just tells us If you encounter a null-terminator ('\0') in s1 before n characters have been compared, then it means the strings are equal up to that point, and you can stop the comparison early
        }
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
    //When we cast the characters to unsigned char, we ensure that we compare them based on their actual byte values (from 0 to 255), which avoids the potential pitfalls of sign extension and guarantees the correct lexicographical comparison.
}
int main()
{
    const char* s1 = "hello";
     const char* s2 = "hello";
     printf("%d\n", ft_strncmp(s1, s2, 3));
}