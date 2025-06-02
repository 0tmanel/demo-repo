#include <unistd.h>
#include <stdio.h>
#include <string.h>
int is_found(char str, char *find)
{
    int i = 0;
    while(find[i])
    {
        if(find[i] == str)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
char* ft_strpbrk(char* str,char* find)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(is_found(str[i], find))
        {
            return str + i;
        }
        i++;
    }
    return NULL;
}
int main ()
{
    char *str = "hello world how are you";
    char* find  = "goal";
   char*s = strpbrk(str, find);
   printf("%s\n", s);
}