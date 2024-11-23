#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_len(char**strs, int size, char *sep)
{
    int i = 0;
     int j = 0;
    int k = 0;
    int l = 0;

    while (i < size)
    {
      j = 0;
      while (strs[i][j] != '\0')
      {
        j++;
      }
      k += j;
      i++;
    }
    while (sep[l] != '\0')
    {
      l++;
    }

   
   return k + (l * size - 1) + 1;

}
char *ft_strjoin(int size, char **strs, char *sep)
{
 
   char* str =  malloc((ft_len(strs, size, sep) ) * sizeof(char));
    if(str == NULL)
    return NULL;
    
    char *tem = str;
    if(size == 0)
    {
      tem[0] = '\0';
      return tem;
    }
    int i = 0;
    int j = 0;
    int k = 0;
 
    while (i < size)
    {
     j = 0;
      
        while (strs[i][j] != '\0')
        {
          str[k] = strs[i][j];
          k++;
          j++;
        }  
        if(i < size - 1)
        {
          j = 0;
          while (sep[j] != '\0')
          {
            str[k] = sep[j];
            k++;
            j++;
          }
        }
        i++;
    }
     str[k] = '\0';
    return tem;

}
int main ()
{
    char* strs[]= { "hello", "world" };
    char *sep = "";
    int size = 2;
    
  char *result = ft_strjoin(size, strs, sep);
  printf("%s", result);
  free(result);
}