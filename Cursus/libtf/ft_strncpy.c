// strncpy copies at most len characters from the string src to dest.

// If src is shorter than len characters, dest is padded with null characters ('\0') until len characters are written.

// If src is longer than len, only the first len characters are copied, and no null terminator is added unless it fits within len.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *ft_strncpy(char *dst, const char *src, size_t len)
{

    int i = 0;
    while (i < len && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    while (i < len)
    {
        dst[i] = '\0';
        i++;
    }
    return dst;
}
int main()
{
    char dest[5];
    const char src[] = "helloworld";
    // char* string = strncpy(dest, src, 5);
    char *string = ft_strncpy(dest, src, 5);
    printf("%s\n", string);
}