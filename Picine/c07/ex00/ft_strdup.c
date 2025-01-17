//strdup is a function in C that duplicates a given string by allocating memory for a new string and copying the content of the original string into it. It returns a pointer to the new string.
//When you want to modify or manipulate a string, but you don’t want to modify the original string itself, you can use strdup to create a copy.
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
}********************************************************/
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
  char *strdup = malloc((len + 1) * sizeof(char));
  if (strdup == NULL)
  {
    return NULL;
  }
  // char*temp = strdup; we can use this when we want to use the pointer notation in the while loop
  // else , if we want to work only with array notation , we can use only strdup and return it

  int i = 0;
  while (src[i] != '\0')
  {
    strdup[i] = src[i];
    i++;
  }
  strdup[i] = '\0';

  return strdup;
  // The pointer strdup will point to the first character ('h'), not the null terminator ('\0').
  //  When you return strdup from the function, you are returning
  // the address of the first character of this memory block, which is strdup[0].
}
int main()
{
  char src[] = "hello world";
  char *temp = ft_strdup(src);
  while (*temp)
  {
    printf("%c", *temp);
    temp++;
  }
  printf("\n");
}
// If you call free() on a pointer that was never allocated by
// one of these functions (or has already been freed), the behavior is undefined.