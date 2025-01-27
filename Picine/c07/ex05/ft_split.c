  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  /*
  int ft_seperator(char c, char * charset)
  {
    int i = 0;
    while (charset[i] != '\0')
    {
        if(c == charset[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
  }
  int ft_count(char* str, char * charset)
  {
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        while(str[i] != '\0' && ft_seperator(str[i], charset))
        i++;
        if(str[i] != '\0')
        count++;
        while(str[i] != '\0' && ! ft_seperator(str[i], charset))
        i++;
    }
    return count;
  }
  int ft_len(char* str, char* charset)
  {
    int i = 0;
    while (str[i] != '\0' && !ft_seperator(str[i], charset))
    {
        i++;
    }
    return i;

  }
  char *ft_word(char* str, char*charset)
  {
   int str_len = ft_len(str, charset); 
   char* string = (char*)malloc((str_len + 1) * sizeof(char));
   int i = 0;
   while (i < str_len)
   {
    string[i] = str[i];
    i++;
   }
   string[i] = '\0';

   return string;
  }
  char **ft_split(char *str, char *charset)
  {
    char **strs = (char**)malloc((ft_count(str, charset) + 1) * sizeof(char*));
    int l  = 0;
    //int i = 0;
    while(*str)
    {
        while (*str != '\0' && ft_seperator(*str, charset))
        str++;
        if(*str)
        {
            strs[l] = ft_word(str, charset);
            l++;
        }
        while (*str != '\0' && !ft_seperator(*str, charset))
        str++;
    }
    strs[l] = 0;

    return strs;

  }
  */
  int main() {
    char str[] = "hello,world,HOW,are,you";
    char charset[] = ",";
/*
    char** arr = ft_split(str, charset);
    if (arr) {
        int i = 0;
        while (arr[i] != NULL) {
            printf("%s\n", arr[i]);
            i++;
        }
    }*/
    char* string; 
    string = (str, charset);
   
        while (string != NULL) {
            printf("%s\n", string);
            string = strtok(str, charset);
        }
    return 0;
}