//One reason to use strnstr() instead of strstr() would be to save time. Obviously searching only n characters is faster than searching what could be a very long string. I can imagine other reasons to use it, but mostly I’ve used strstr() in my code.
//it is the same as strstr,  just in strnstr we add i < len at the outer loop and i + j < len in the inner
#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i = 0;
    while (haystack[i] != '\0' && i < len)
    {
        size_t j = 0;
        while(haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
        {
            j++;
        }
        if(needle[j] == '\0')
        {
            return (char*)(haystack + i);
        }
        i++;
    }
    return NULL;
}

int main ()
{
    const char*haystack = "hello world, my name is otman";
    const char* needle = "name";
    printf("%s\n", strnstr(haystack, needle, 20));
    //printf("%s\n", ft_strnstr(haystack, needle, 20));
}