#include <stdlib.h>
#include <stdio.h>

int ft_len(char *str)
{
    int i = 0;
    if(str[i] == ' ')
    {
       i++;
    }
   while(str[i] != '\0'  )
       {
        if((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        {
            break;
        }
        i++;
    }
    return i;
}
int ft_strlen(char *str)
{
    int i = 0;
    int index = 0;
    while (str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i]== '\0')
        {
            index++;
        }
        i++;
    }
    
    return index;
    
}
char * ft_word(char *str)
{
    int i = 0;
    int len = ft_len(str);
    
    char *string = (char*)malloc((len + 1) * sizeof(char));
   while(i <= len)
   {
        string[i] = str[i];
        i++;
   }
    string[i] = '\0';
    return string;
}
char    **ft_split(char *str)
{
    char **string = (char**)malloc((ft_strlen(str) + 1) * sizeof(char*));
    if(string == NULL)
    {
        return NULL;
    }
    int l = 0;
    
    while (*str)
    {
           if(l == 0 || *str == ' ' || *str == '\t' || *str == '\n' || *str== '\0' )
           {
            string[l] = ft_word(str);
            l++;
           }
            str++;
    }
    string[l] = NULL;
    return string;

}


int main ()
{
    char str[] = "hello word how are you";
    
   char **string = ft_split(str);
   int i = 0;
   while (string[i] != NULL)
   {
    printf("%s\n", string[i]);
    i++;
   }
}


/*
#include <stdlib.h>
#include <stdio.h>
int ft_len(char *str)
{
    int i = 0;
   while(str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') )
       {
        i++;
    }
    return i;
}
int ft_strlen(char *str)
{
    int i = 0;
    int index = 0;
    while (str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i]== '\0')
        {
            index++;
        }
        i++;
    }
    
    return index;
    
}
char * ft_word(char *str)
{
    int i = 0;
    int len = ft_len(str);
    printf("%d\n", len);
    char *string = malloc(len + 1 * sizeof(char));
   while(i < len)
   {
        string[i] = str[i];
        i++;
   }
    string[i] = '\0';
    return string;
}
char    **ft_split(char *str)
{
    char **string = malloc(ft_strlen(str) + 1 * sizeof(char*));
    if(string == NULL)
    {
        return NULL;
    }
    int l = 0;
    int f = 1;
    
    while (*str)
    {
           while(*str && (*str == ' ' || *str == '\t' || *str == '\n'))
            {
                str++;
            }
            if(*str)
            {
            string[l] = ft_word(str);
            l++;
            }
            while(*str && (*str != ' ' || *str != '\t' || *str != '\n' ))
            str++;
    }
    string[l] = NULL;
    return string;

}*/