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
/*int ft_len(char *src)
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
  { int len = ft_len(src);
  char* strdup = malloc((len + 1) * sizeof(char));
  if(strdup == NULL)
  {
    return NULL;
  }
  //char*temp = strdup; we can use this when we want to use the pointer notation in the while loop
  //else , if we want to work only with array notation , we can use only strdup and return it
  
  int i = 0;
  while (src[i] != '\0')
  {
    strdup[i] = src[i];
    i++;
  }
  strdup[i] = '\0';
  
  return strdup;
  //The pointer strdup will point to the first character ('h'), not the null terminator ('\0').
  // When you return strdup from the function, you are returning 
  //the address of the first character of this memory block, which is strdup[0].

  }
  int main()
  {
    char src[] = "hello world";
    char* temp = ft_strdup(src);
    while (*temp)
    {
        printf("%c", *temp);
        temp++;
    }
    printf("\n");
    
  }
//If you call free() on a pointer that was never allocated by 
//one of these functions (or has already been freed), the behavior is undefined.