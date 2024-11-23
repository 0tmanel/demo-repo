#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*void *ft_strdup(char *src)
{
    char* dup;
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    int len = i + 1;
    dup = malloc(len* sizeof(char));
    if(dup == NULL)
    return NULL;
    int j = 0;
    char * tem = dup;
    while (src[j] != '\0')
    {
        *dup = src[j];
        j++;
        dup++;
    }
    *dup = '\0';
    
   return tem;

}
int main ()
{
    char src[] = "hello otman";
  
   char* dup = ft_strdup(src);
   printf("%s", dup);
}*/
int ft_len(char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    return i;
}
 char *ft_strdup(char *src)
 {
   int len = ft_len(src);
   char*strdp = malloc(sizeof(len + 1));//always check if the memory is valid
   char* temp = strdp;
   int i = 0;
   while (src[i] != '\0')
   {
    strdp[i] = src[i];
    i++;
   }
   return temp;
 }
int main (void)
{
    char src[] = "hello world , how are you ?";
     char *src2 = ft_strdup(src);
     int i = 0;
     while (src2[i] != '\0')
     {
        printf("%c", src2[i]);
        i++;
     }
}