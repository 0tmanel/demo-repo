//The function strchr() searches the string s for the first occurrence of the character c (converted to a char).
//It returns a pointer to the first matching character, or NULL if the character is not found.

//🔸 If c is '\0', strchr will locate the null terminator at the end of the string.
//Return value:
//A pointer to the first occurrence of c in the string s
//NULL if the character is not found
#include <stdio.h>
char * ft_strchr( const char *s, int c)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
        {
            return (char*)s + i;
        }
        i++;
    }
    if(c == '\0')
        return (char*) s + i;
    return NULL;
}
int main ()
{
    const char* s = "hello world";
    int c = '\0';
    printf("%s\n", ft_strchr(s, c));
}