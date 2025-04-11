#include <stdlib.h>
#include <stdio.h>
#define IS_WHITESPACE(c) ((c) == ' ' || (c) == '\n' || (c) == '\t')
 int ft_strlen(char const *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 void allocate(char const * s, int* start, int* last)
 {
    while(IS_WHITESPACE(s[*start]))
        (*start)++;
    while(IS_WHITESPACE(s[*last]))
        (*last)--;
 }
char* ft_strtrim(char const *s)
{
    if(!s)
    return NULL;
    int len = ft_strlen(s) - 1;
    int start = 0;
     allocate(s, &start, &len);
    // printf("%d  %d", start, len);
    int sum = len - start + 1 ;
    char *string = malloc(( sum + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0;
   while(i < sum)
   {
    string[i] = s[start + i];
    i++;
   }
    string[i] = '\0';
    return string;
}
int main ()
{
    char const *s = "  \t howare you   ";
    printf("%s\n", ft_strtrim(s));
    //ft_strtrim(s);
} 