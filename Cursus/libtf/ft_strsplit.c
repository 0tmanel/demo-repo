#include <stdlib.h>
#include <stdio.h>
int ft_count2(char s, char c)
{
    return s == c;
}
int ft_count1(char const *s, char c)
{
    int i = 0;
    int index = 0;
    while(s[i] != '\0')
    {
        if(s[i] && ft_count2(s[i] , c))
                i++;
        if(s[i] )
            index++;
        while(s[i] && !ft_count2(s[i] , c))
            i++;
    }
    return index;
}
int ft_strlen(char const *s, char c)
{
    int i = 0;
    while(s[i] && !ft_count2(s[i] , c))
    i++;

    return i;
}
char* ft_word(char const *s, char c)
{
    int length = ft_strlen(s, c);
    char *string = malloc((length + 1) * sizeof(char));
    if(!string)
    return NULL;
    int i = 0;
    while(i < length){
        string[i] = s[i];
        i++;
    }
    string[i]= '\0';
    return string;
}
char ** ft_strsplit(char const *s, char c)
{
    char** string = malloc(ft_count1(s, c) * sizeof(char*));
    int i = 0;
    while(*s)
    {
        if(*s && ft_count2(*s , c))
            s++;
        if(*s)
        {
        string[i] = ft_word(s, c);
        i++;
        }
        while(*s && !ft_count2(*s , c))
            s++;
    }
    return string;
}
int main ()
{
    char const s[] = "hello world how are you";
    char c = ' ';
  char **string =  ft_strsplit(s, c);
  int i = 0;
  while(string[i])
  {
    printf("%s\n", string[i]);
    i++;
  }
}