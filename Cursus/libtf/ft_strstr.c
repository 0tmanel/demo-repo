 //The strstr() function locates the first occurance of string s2 within string s1. That location is returned as a char pointer — the address of s2 inside s1. It’s not an offset, but a memory location.
 #include <stdio.h>
 char *ft_strstr(const char *haystack, const char *needle)
 {
    int i = 0;
    while(haystack[i] != '\0')
    {
        int j = 0;
        while(haystack[j + i] == needle[j] && needle[j] != '\0')
        {
            j++;
        }
        if(needle[j] == '\0'){
            return (char*)(haystack + i);
        }
        i++;
    }
    return NULL;
 }
 int main()
 {
    const char* haystack = "hello world";
    const char* needle = "worl";
    printf("%s\n", ft_strstr(haystack, needle));
 }