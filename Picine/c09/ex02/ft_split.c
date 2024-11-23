#include <stdlib.h>
#include <stdio.h>
int is_sep(char c, char* charset)
{
    int i = 0;
    while (charset[i] != '\0')
    {
        if(charset[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int ft_count(char* str, char* charset)
{
    int count = 0;
    int in_word = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if(is_sep(str[i], charset) )
        {
            if(in_word)
            {
            count++;
            in_word = 0;
            }
        }
        else 
        in_word = 1;
        i++;
    }
    if(in_word)
    {
        count++;
    }
    return count;
}
char *ft_extract(char *str, int start, int end)
{
    int len = end - start + 1;
    char *arr;
    arr = malloc((len  + 1)* sizeof(char));//allocate memory plus the null character
    if(!arr)
    return NULL;//RETUNR  null if the memory fail
  int i = 0;
    while (i < len)
    {
        arr[i] = str[start + i];
        i++;
    }
    arr[len] = '\0'; 
    return arr;
}
char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = i - 1;
    int num_sub = ft_count(str, charset);
  
   char** arr = malloc   ((num_sub + 1) * sizeof(char*));
   if(arr == NULL)
   {
    return NULL;
   }
    while (str[i] != '\0')
    {
     if(is_sep(str[i], charset))
     {
        if(i > start)
        {
       arr[j] = ft_extract(str, start, i - 1);
    
       j++;
        }
       start = i + 1;
     }
     i++;
     
    }
    if(i > start)
    {
        arr[j] = ft_extract(str, start, i - 1);
        j++;
    }
    arr[j] = NULL;;
    return arr;

}
int main ()
{
    char str[] = "hello,world.otman";
    char charset[] = ",.";

  char **result =  ft_split(str, charset);
  if(result)
  {
    char **current = result;
    while (*current != NULL)
    {
        printf("%s\n", *current);
        current++;
    }
  }
}