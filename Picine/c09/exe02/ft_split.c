 #include <stdio.h>
 #include <stdlib.h>
 int separator(char c, char*charset)
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
 int ft_count(char*str, char*charset)
 {
   int index = 0;
   int i = 0;
   while (str[i] != '\0')
   {
      while (str[i] != '\0' && separator(str[i], charset))
      {
         i++;
      }
      if(str[i] != '\0')
      {
         index++;
      }
      while (str[i] != '\0' && !separator(str[i], charset))
      {
         i++;
      }
   }
   return index;
 }
 int ft_strlen(char *str, char *charset)
 {
   int i = 0;
   while (str[i] != '\0' && !separator(str[i], charset))
   {
      i++;
   }
   return i;
 }
 char* word(char*str, char *charset)
 {
   int i = 0;
   int len = ft_strlen(str, charset);
   char *string = malloc((len + 1) * sizeof(char));
   while (i < len)
   {
      string[i] = str[i];
      i++;
   }
   string[i] = '\0';
   return string;
 }
 char **ft_split(char *str, char *charset)
 {
   int len = ft_count(str, charset);
  
    char **string = malloc ((len + 1) * sizeof(char*));
    int l = 0;
    while (*str)
    {
      while (*str && separator(*str, charset))
      {
         str++;
      }
      if(*str)
      {
         string[l] = word(str, charset);
         l++;
      }
      while (*str && !separator(*str, charset))
      {
         str++;
      }
    }
    string[l] = 0;
    return string;
 }
 int main ()
 {
    char *str = "hello otman how are you";
    char *charset = ", ";
  char **string = ft_split(str, charset);
   
   while (*string)
   {
    printf("%s\n", *string);
    string++;
   }
   
 }